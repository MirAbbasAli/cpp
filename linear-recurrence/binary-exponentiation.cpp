#include<bits/stdc++.h>
using namespace std;
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long int
#define endl "\n"

const int M = 1e9+7;

int power(int a, int b){
    if (b == 0) return 1;
    int tmp = power(a, b/2);
    int result = (tmp*tmp)%M;
    if (b&1) result = (result*a)%M;
    return result;
}

int powerIterative(int a, int b){
    int result = 1;
    while (b){
        // If last-bit is set multiply by a
        if (b&1) result = (result*a)%M;
        a = (a*a)%M;
        // Right shift 'b' by 1 bit
        b >>= 1;
    }
    return result;
}

void solve(){
    int a, b;
    // representing a^b
    cin >> a >> b;
    cout << powerIterative(a, b) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}