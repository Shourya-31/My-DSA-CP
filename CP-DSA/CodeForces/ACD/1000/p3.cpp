#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string ans = "";
    for(char c : s){
        if(c!='A' && c!='E' && c!='I' && c!='O' && c!='U' && c != 'Y' && c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c != 'y'){
            ans += '.';
            ans += tolower(c);
        }
    }

    cout << ans;
}