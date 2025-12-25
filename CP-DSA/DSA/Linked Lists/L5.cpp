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

void splitMid(head){
    
}

void mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* rightHead = splitMid(head);

    mergeSort(head); //left head
    mergeSort(rightHead); //right head

    merge(head,rightHead);
}

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_front(5);

    
}
