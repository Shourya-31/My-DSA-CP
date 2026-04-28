// #include<bits/stdc++.h>
// using namespace std;
// using ll = long long;

// void solve(){
//     ll t;
//     cin>>t;

//     while(t--){
//         ll x,y,k;
//         cin>>x>>y>>k;

//         // 2 conditions are there:-
//         // a.) exchange 1 stick for x sticks => stick = stick+x-1;
//         // b.) exchange y sticks for 1 coal => stick-y, coal+1;

//         // Goal:- We need k torches
//         // To make 1 torch we need 1 stick and 1 coal

//         // Answer- Min ops to make k torches

//         // Example:- Assuming worst case scenario, we have 1 sticks and 0 coals, we need k sticks and k coals to make k torches.
//         // x=2 y=1 k=5
//         // a=> s=2
//         // a=> s=3
//         // a=> s=4
//         // a=> s=5
//         // a=> s=6
//         // b=> s=5 c=1
//         // b=> s=4 c=2
//         // b=> s=3 c=3
//         // b=> s=2 c=4
//         // b=> s=1 c=5
//         // a=> s=2 c=5
//         // a=> s=3 c=5
//         // a=> s=4 c=5
//         // a=> s=5 c=5
//         // s=5, c=5 and thus we have 5 torches = k
//         // therefore answer is 14

//         // now:-
//         ll stick = k*(y+1) - 1;
//         ll ans = ceil(stick/(x-1)) + k;

//         cout<<ans<<"\n";

//     }
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Function to perform ceiling division of a by b
long long ceil_division(long long a, long long b) {
	return (a + b - 1) / b;
}

int main() {
	int t;
	cin >> t; // Read the number of test cases
	while (t--) {
		long long x, y, k;
		cin >> x >> y >> k; // Read the values of x, y, and k for each test case

		// Calculate the number of sticks gained per trade
		long long sticks_gained_per_trade = x - 1; // If we give 1 stick and get x back, we gain x-1 sticks

		// Calculate the total number of sticks needed to craft k torches
		// 1 torch requires 1 stick and 1 coal, hence k torches require k sticks and k coals
		long long sticks_needed = k * y + k - 1;

		long long trades = 0;
		// Calculate the number of trades needed to gain the required number of sticks
		trades += ceil_division(sticks_needed, sticks_gained_per_trade);
		// Add the number of trades needed to get k coals
		trades += k;

		// Output the total number of trades required
		cout << trades << endl;
	}
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
