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

    // ~Node()
    // {
    //     cout << "Node destructor for data = " << data << endl;
    //     if (next != NULL)
    //     {

    //         delete next;
    //         next = NULL;
    //     }
    // }
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
        cout << "NULL" << endl;
    }

    void insertAtMid(int val, int idx)
    {
        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < idx - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position is Invalid" << endl;
            }
            temp = temp->next;
        }
        // temp now points to idx-1
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // ~List()
    // {
    //     cout << "~List" << endl;
    //     if (head != NULL)
    //     {
    //         delete head;
    //         head = NULL;
    //     }
    // }

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

    void pop_back()
    {
        Node *temp = head;

        // while(temp->next != tail){
        //     temp = temp->next;
        // }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int search(int key) // TC: O(n)
    {
        Node *temp = head;
        int idx = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "Key found at: " << idx << endl;
            }

            temp = temp->next;
            idx++;
        }

        return -1;
    }

    int helper(Node *temp, int key)
    {
        if (temp == NULL)
        {
            return -1;
        }

        if (temp->data == key)
        {
            return 0;
        }

        int idx = helper(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }

        return idx + 1;
    }

    int RecursiveSearch(int key)
    {
        cout << "Key is at: " << helper(head, key) << endl;
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

    l1.insertAtMid(10, 3);

    l1.pop_front();

    l1.pop_back();

    l1.printLL();

    l1.search(10);
    l1.RecursiveSearch(3);
    return 0;
}