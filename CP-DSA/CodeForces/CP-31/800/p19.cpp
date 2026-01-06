// Solution
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[n];

        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        int neg = 0;
        int pos = 0;

        for(int i=0; i<n; i++){
            if(a[i] == 1){
                pos++;
            }else{
                neg++;
            }
        }

        int ops = 0;

        while(neg > pos || neg % 2 == 1){
            ops++; // Increment operations as we convert a -1 to 1
            neg--;
            pos++;
        }

        cout<<ops<<endl;
    }
}
