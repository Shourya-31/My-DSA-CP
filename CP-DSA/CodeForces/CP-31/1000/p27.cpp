#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isFair(ll n){
    ll num = n;
    while(num != 0){
        int a = num%10;
        if(a != 0 && n%a != 0) return false;
        num /= 10;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    while(t--){
        ll n; cin>>n;
        while(!isFair(n)) n++;
        cout << n << "\n";
    }
    return 0;
}