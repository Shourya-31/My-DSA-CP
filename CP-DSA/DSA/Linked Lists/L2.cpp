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

// Linked List: A linear data structure where each element points to the next, allowing for efficient insertions and deletions.
// Does not require contiguous memory allocation like arrays.
// Time Complexity: O(1) for insertions and deletions at the head, O(n) for search.
// Space Complexity: O(n) for storing n elements.

// Implementation:
// 2 Ways: 1. Using STL (Standard Template Library) 2. Class-based implementation
// We will make a class named Node to represent each node in the linked list.
// And data members will be 'data' and 'next' pointer.
// And we will make a List class which will be collection of nodes.

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

int main()
{
    List l1;
    l1.push_front(1);
    l1.push_front(2);
    l1.push_front(3);
    l1.push_front(4);
    l1.push_front(5);

    l1.getTail()->next = l1.getHead();

    isCycle(l1.getHead());
}
