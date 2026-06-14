#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <limits>
#include <iomanip>
#include <functional>
#include <utility>
#include <cctype>
#include <cassert>
#include <climits>
using namespace std;

#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

// Shortcuts
#define int long long
#define vl vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define invl(v, n) rep(i, n) cin >> v[i];
#define outvl(v)          \
    for (auto i : v)      \
        cout << i << " "; \
    cout << endl;
#define pii pair<int, int>
#define maxi priority_queue<int>
#define mini priority_queue<int, greater<int>, vector<int>>
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pm cout << "-1" << endl
#define B break
#define C continue
#define ss second
#define ff first
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define sz(x) (int)(x).size()

typedef vector<vl> vvi;
typedef vector<pair<int, int>> vpii;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;

// Loop macros
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep_range(i, a, b) for (int i = a; i < b; ++i)
#define rrep(i, n) for (int i = n - 1; i >= 0; --i)
#define for_each(x, container) for (auto &x : container)

/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Maths
vector<int> spf;
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
vector<pair<int, int>> Primefactors(int n)
{
    vector<pair<int, int>> arr;
    for (int d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            int c = 0;
            while (n % d == 0)
            {
                c++;
                n /= d;
            }
            arr.push_back(make_pair(d, c));
        }
    }
    if (n > 1)
        arr.push_back(make_pair(n, 1));
    return arr;
}
vector<pair<int, int>> primespf(int x, vector<int> &spf)
{
    vector<pair<int, int>> ans;
    while (x != 1)
    {
        int prime = spf[x];
        int c = 0;
        while (x % prime == 0)
        {
            x /= prime;
            c++;
        }
        ans.push_back(make_pair(prime, c));
    }
    return ans;
}
vector<int> factors(int n)
{
    vector<int> arr;
    for (int d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            arr.push_back(d);
            if (n / d != d)
                arr.push_back(n / d);
        }
    }
    return arr;
}
vector<int> getSpf(int n)
{
    int maxn = n + 1;
    vector<int> spf(maxn);
    for (int i = 0; i < maxn; i++)
    {
        spf[i] = i;
    }
    for (int i = 2; i * i < maxn; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < maxn; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}
vector<int> Primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            ans.push_back(i);
    }
    return ans;
}
bool isPrime(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime[n];
}
int modExp(int base, int exp, const int mod)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}
int invMod(int P, int Q, const int MOD)
{
    int Q_inv = modExp(Q, MOD - 2, MOD);
    return (P * Q_inv) % MOD;
}
void factorials(int n, int mod, vector<int> &fact, vector<int> &inv)
{
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[n] = modExp(fact[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; i--)
    {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
}
int combination(int n, int r, int mod, const vector<int> &fact, const vector<int> &inv)
{
    if (r > n || r < 0)
        return 0;
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}
int binaryExponentiation(int base, int exp, int mod)
{
    int result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exp /= 2;
        base = (base * base) % mod;
    }
    return result;
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Bit Manipulation
template <typename T>
void unset_bit(T &n, int pos)
{
    T mask = ~(static_cast<T>(1) << pos);
    n = n & mask;
}
template <typename T>
int check_bit(T num, int i) { return (num & (1 << i)) != 0; }
template <typename T>
void set_bit(T &num, int i) { num |= (1 << i); }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);

        vector<vector<int>> pos(k + 1);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            pos[a[i]].push_back(i + 1);
        }

        // int ans = 0;
        bool same_array = true;

        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                same_array = false;
                break;
            }
        }

        // int steps = 0;

        // for (int i = 1; i < n; i++)
        // {
        //     if (a[i] == a[i - 1])
        //     {
        //         steps = 0;
        //     }
        //     else if (a[i] != a[i - 1])
        //     {
        //         steps++;
        //     }
        // }

        if (same_array)
        {
            cout << 0 << endl;
            continue;
        }

        // else
        // {
        //     cout << (n - steps + 2) << endl;
        // }

        int ans = n;

        // testing each color
        for (int color = 1; color <= k; color++)
        {
            int mx1 = 0; // largest gap
            int mx2 = 0; // second largest gap

            int prev = 0; // left boundary

            for (int p : pos[color])
            {
                int gap = p - prev - 1;

                mx2 = max(mx2, min(mx1, gap));
                mx1 = max(mx1, gap);

                prev = p;
            }

            int gap = (n + 1) - prev - 1;
            // gap to right boundary

            mx2 = max(mx2, min(mx1, gap));
            // The smaller of (mx1, gap) is a candidate for becoming
            // the second largest gap.
            // Compare that candidate with the current second largest gap
            // and keep the larger one.

            mx1 = max(mx1, gap);
            // Update the largest gap seen so far.

            ans = min(ans, max(mx2, mx1 / 2));

            // Repaint one plank in the largest gap

            int cost = max(mx2, mx1 / 2);

            ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}