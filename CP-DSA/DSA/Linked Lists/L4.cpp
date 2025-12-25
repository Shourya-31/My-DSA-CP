#include <bits/stdc++.h>
using namespace std;

void printLL(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> l1;

    l1.push_front(2);
    l1.push_front(1);
    l1.push_back(3);
    l1.push_back(4);

    // list<int>::iterator itr; // Iterator to traverse the LL
    // There exists begin() and end()
    // which returns iterator of head and next of tail respectively
    printLL(l1);
    cout<<l1.size()<<endl;
    cout<<"head = "<<l1.front()<<"\n";
    cout<<"tail = "<<l1.back()<<"\n";

    l1.pop_front();
    l1.pop_back();
    printLL(l1);
    return 0;
}