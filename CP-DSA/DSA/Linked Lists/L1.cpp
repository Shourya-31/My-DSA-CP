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

    void printLL()
    {
        Node *temp = head;
        while (temp != NULL) // TC: O(n)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    List l1;

    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);
    // 1->2->3->NULL
    l1.push_back(4);

    l1.printLL();
    return 0;
}

// 1/HEAD -> 2/NEXT -> 3/NULL