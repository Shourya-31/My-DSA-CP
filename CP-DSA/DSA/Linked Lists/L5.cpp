// Merge Sort on LL

// Peudo Code:
// MS(head){
//     rightHead = splitAtMid(head)
//     MS(head) // Sorted
//     MS(rightHead) // Sorted

//     merge(head, rightHead)
// }

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val); // dynamic

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {

        if (head == NULL)
        {
            cout << "LL is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;

        temp->next = NULL;
        delete temp;
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL) // TC: O(n)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            cout << "Cycle exists\n";
            return true;
        }
    }

    cout << "Cycle doesnt exists\n";
    return false;
}

Node *splitMid(Node *head)
{
    // Finding mid point via slow & fast pointer
    // When fast reaches NULL at next then slow reaches at mid
    // we will track the prev of slow to find the mid value
    // to break the connection: prev->next = NULL
    // This is for Even LL
    // For Odd LL, same procedure will be followed

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL; // Split at Mid
    }

    return slow; // slow = righrtHead
}

Node *merge(Node *left, Node *right)
{
    List ans;
    Node *i = left;
    Node *j = right;

    while (i != NULL && j != NULL)
    {
        if (i->data <= j->data)
        {
            ans.push_back(i->data);
            i = i->next;
        }
        else
        {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }

    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.getHead();
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *rightHead = splitMid(head);

    Node *left = mergeSort(head);       // left head
    Node *right = mergeSort(rightHead); // right head

    return merge(left, right);
}

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_front(5);

    printLL(l1.getHead());
    Node *sortedHead = mergeSort(l1.getHead()); 
    printLL(sortedHead);
}
