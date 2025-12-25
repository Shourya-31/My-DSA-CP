// Remove Cycle in a LL
// Steps:
// 1.) Detection of Cycle
// 2.) We re-initialize the slow to head
// 3.) Then we will make slow and fast move 
//     and finally they will meet at the connection point
// 4.) At the end we will identify the last node (prev of fast before it meet at slow again) 
//     then we will point its next pointer to NULL

// Peuso Code:
// Detect Cycle
// slow = head
// while(slow != fast){
//    slow->+1
//    fast->+1
// }
// prev = Last Node
// prev->next = NULL


// Code:



// Detect a Cycle/Loop in a LL:
// We will use Floyd's Cycle Finding Algorithm
// 2 pointers will be there: slow+1, fast+2
// slow = slow->next & fast = fast->next->next
// There will be one instance when slow and fast will collide at one node
// At that moment we'll detech that there is a cycle present in LL

// When there is no cycle, then these pointers will never meet

// pseudo code:
// fast = slow = head;
// while(fast != NULL && fast->next != NULL){
//   slow = slow->next
//   fast = fast->next->next
//   if (slow = fast){
//       break; => Cycle
//   }
// }

// Code:

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

void removeCycle(Node* head){
    //detect cycle
    Node* slow = head;
    Node* fast = head;
    bool cycleFound = false;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"Cycle Exists\n";
            cycleFound = true;
            break;
        }
    }

    if(!cycleFound){
        cout<<"Cycle doesnt exist\n";
        return;
    }
    
    // Re-initializing
    slow = head;
    if(slow == fast){ // when tail->head
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
        cout<<"Cycle removed\n";

    }else{
        Node* prev = fast;
        while(slow != fast){
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = NULL;
        cout<<"Cycle removed\n";
    }

}

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_front(5);

    l1.getTail()->next = l1.getHead();

    removeCycle(l1.getHead());
}



