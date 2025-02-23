#include<bits/stdc++.h>
using namespace std;
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long int
#define endl "\n"

int multiplyRecur(int a, int b){
    if (b == 0) return 0;
    int tmp = multiplyRecur(a, b/2);
    int result = 2*tmp;
    if (b&1) result += a;
    return result;
}

int multiply(int a, int b){
    int res = 0;
    while (b){
        if (b&1) res += a;
        a *= 2;
        b = b/2;
    }
    return res;
}

// With mod c
int multiply(int a, int b, int c){
    int res = 0;
    while (b){
        if (b&1) res = (res+a)%c;
        a = (2*a)%c;
        b >>= 1;
    }
    return res;
}


void solve(){
    int a, b, c;
    // representing a * b
    cin >> a >> b >> c;;
    cout << multiply(a, b, c) << endl;
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