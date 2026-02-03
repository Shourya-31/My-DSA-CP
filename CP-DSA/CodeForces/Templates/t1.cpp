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
 
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr);
 
// Shortcuts
#define int long long
#define vl vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define invl(v, n) rep(i, n) cin >> v[i];
#define outvl(v) for(auto i:v) cout << i << " "; cout << endl;
#define pii pair<int,int>
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
typedef vector<pair<int, int> > vpii;
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
int gcd(int a, int b) { while (b) { a %= b; swap(a, b); } return a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
vector<pair<int, int > > Primefactors(int n) { vector<pair<int, int > > arr; for (int d = 2; d * d <= n; d++) { if (n % d == 0) { int c = 0; while (n % d == 0) { c++; n /= d; } arr.push_back(make_pair(d,c)); } } if (n > 1) arr.push_back(make_pair(n,1)); return arr; }
vector<pair<int, int > > primespf(int x, vector<int>& spf) { vector<pair<int, int > > ans; while (x != 1) { int prime = spf[x]; int c = 0; while (x % prime == 0) { x /= prime; c++; } ans.push_back(make_pair(prime,c)); } return ans; }
vector<int> factors(int n) { vector<int> arr; for (int d = 1; d * d <= n; d++) { if (n % d == 0) { arr.push_back(d); if (n / d != d) arr.push_back(n / d); } } return arr; }
vector<int> getSpf(int n) { int maxn = n + 1; vector<int> spf(maxn); for (int i = 0; i < maxn; i++) { spf[i] = i; } for (int i = 2; i * i < maxn; i++) { if (spf[i] == i) { for (int j = i * i; j < maxn; j += i) { if (spf[j] == j) { spf[j] = i; } } } } return spf; }
vector<int> Primes(int n) { vector<bool> is_prime(n + 1, true); is_prime[0] = is_prime[1] = false; vector<int> ans; for (int i = 2; i * i <= n; i++) { if (is_prime[i]) { for (int j = i * i; j <= n; j += i) is_prime[j] = false; } } for (int i = 2; i <= n; i++) { if (is_prime[i]) ans.push_back(i); } return ans; }
bool isPrime(int n) { vector<bool> is_prime(n + 1, true); is_prime[0] = is_prime[1] = false; for (int i = 2; i * i <= n; i++) { if (is_prime[i]) { for (int j = i * i; j <= n; j += i) is_prime[j] = false; } } return is_prime[n]; }
int modExp(int base, int exp, const int mod) { int result = 1; while (exp > 0) { if (exp % 2 == 1) { result = (result * base) % mod; } base = (base * base) % mod; exp /= 2; } return result; }
int invMod(int P, int Q, const int MOD) { int Q_inv = modExp(Q, MOD - 2, MOD); return (P * Q_inv) % MOD; }
void factorials(int n, int mod, vector<int>& fact, vector<int>& inv) { fact[0] = 1; for (int i = 1; i <= n; i++) { fact[i] = (fact[i - 1] * i) % mod; } inv[n] = modExp(fact[n], mod - 2, mod); for (int i = n - 1; i >= 0; i--) { inv[i] = (inv[i + 1] * (i + 1)) % mod; } }
int combination(int n, int r, int mod, const vector<int>& fact, const vector<int>& inv) { if (r > n || r < 0) return 0; return fact[n] * inv[r] % mod * inv[n - r] % mod; }
int binaryExponentiation(int base, int exp, int mod) { int result = 1; base %= mod; while (exp > 0) { if (exp % 2 == 1) { result = (result * base) % mod; } exp /= 2; base = (base * base) % mod; } return result; }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// Bit Manipulation
template <typename T> void unset_bit(T &n, int pos) { T mask = ~(static_cast<T>(1) << pos); n = n & mask; }
template <typename T> int check_bit(T num, int i) { return (num & (1 << i)) != 0; }
template <typename T> void set_bit(T &num, int i) { num |= (1 << i); }
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/