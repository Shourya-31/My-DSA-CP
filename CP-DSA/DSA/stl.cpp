#include<bits/stdc++.h>
using namespace std;

int main() {
    // Pairs: Store two values in a single variable
    pair<int, int> p = {1,3};
    cout<<p.first<<" "<<p.second<<endl;
    pair<int, pair<int,int>> p1 = {1, {3,4}};
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;

    // Vectors: Dynamic Arrays
    vector<int> v;

    v.push_back(10); // Insert 10 at the end of the container
    v.emplace_back(20); // More efficient way to insert 20 at the end
    // Dynamic resizing happens automatically
    cout<<"Vector elements: ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    vector<pair<int,int>> vec;

    vector<int> v1(5,100); 
    // Vector of size 5, all elements initialized to 100
    vector<int> v2(5); 
    // Vector of size 5, elements initialized to 01
    vector<int> v3(v1);
    // Copy of vector v1

    vector<int>::iterator it = v1.begin(); // Printing memory address of first element
    cout<<"First element of v1: "<<*it<<endl;
    // Iterator pointing to the first element of v1

    it = it + 1; // Iterator now points to the second element
    cout<<"Second element of v1: "<<*it<<endl;         
    
    vector<int>::iterator it1 = v1.end();
    // Iterator pointing to one position past the last element
    cout<<"Element before end(): "<<*(it1 - 1)<<endl;
    // end() points to position just after the last element

    vector<int>::reverse_iterator it2 = v1.rend();
    // Reverse iterator pointing to one position before the first element

    cout<<v[0]<<" "<<v.at(0)<<endl;
    cout<<v.back()<<endl; // Last element of the vector

    for (auto it = v1.begin(); it != v1.end(); it++) {
        cout<<*it<<" ";
    }
    // auto: Automatically deduces the type of iterator
    
    // Deletion in vector
    v1.erase(v1.begin() + 1);
    // erase(position): Deletes element at the specified position
    cout<<"\nAfter erasing second element: ";

    // Insertion in vector
    v1.insert(v1.begin() + 1, 200);
    // insert(position, value): Inserts value at the specified position
    cout<<"\nAfter inserting 200 at second position: "; 

    v1.insert(v1.begin() + 1, 2, 300);
    // insert(position, count, value): Inserts 'value' 'count' times at the specified position
    cout<<"\nAfter inserting 300 two times at second position: ";

    vector<int> copy = {1, 2, 3};
    v1.insert(v1.begin() + 1, copy.begin(), copy.end());
    // Inserting a range of elements from another container

    cout<<v.size()<<endl; // Size of the vector
    v.pop_back(); // Removes the last element
    v.swap(v1); // Swaps contents of v and v1
    v.clear(); // Clears all elements from the vector
    v.empty(); // Checks if the vector is empty
}