#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    vector<ll> primes;
    for (ll i = 2; i <= 1e6; i++)
    {
        bool is_prime = true;
        for (ll j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
        {
            primes.push_back(i);
        }
    }
    ll t;
    cin >> t;
    while (t--)
    {
        // a has at least 4 divisors;
        // difference between any two divisors of a is at least d
        ll d;
        cin >> d;

        ll p = -1;
        for(ll i=0; i<primes.size(); i++){
            if(primes[i] >= (d+1)){
                p = primes[i];
                break;
            }
        }

        ll q = -1;
        for(ll i=0; i<primes.size(); i++){
            if(primes[i] >= (p+d)){
                q = primes[i];
                break;
            }
        }

        ll a = min(1LL*p*p*p, 1LL*p*q);
        cout<<a<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}