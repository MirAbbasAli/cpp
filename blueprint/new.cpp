#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define endl "\n"

#define si set <int>
#define vi vector <int>
#define pii pair <int, int>
#define vpi vector <pii>
#define mii map <int, int>
#define que_max priority_queue <int>
#define que_min priority_queue <int, vi, greater<int>>
#define sz(x) ((int) x.size())

#define print(a) for (auto x : a) cout << x << " "; cout << endl
#define print1(a) for (auto x: a) cout << x.F << " " << x.S << endl
#define print2(a,x,y) for (int i = x, i < y; i++) cout << a[i] << " "; cout << endl
#define bug(...) ___f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


void solve(){

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;
	while (t--) solve();

	return 0;
}