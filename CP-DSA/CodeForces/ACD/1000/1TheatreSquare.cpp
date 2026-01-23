#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long tilesN = (n + a - 1) / a;
    long long tilesM = (m + a - 1) / a;

    cout << tilesN * tilesM << endl;
}