#include<bits/stdc++.h>
using namespace std;
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long int
#define endl "\n"

vi dp(1e9,-1);


/*
// Recursion based fibonacci solution O(2^n)
int fib(int n){
    // recursion dp based
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

// Fibonacci DP with recursion O(n)
int fib(int n){
    if (n <= 1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}

// Iterative approach for solving fibonacci series O(n)
int fib(int n){
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}
*/
const int sz = 2;
const int mod = 1e9 + 7;

struct Matrix{
    int mat[sz][sz];

    Matrix(){
        memset(mat, 0, sizeof(mat));
    }

    void identity(){
        // Create the Identity Matrix I2 = [[1,0],[0,1]] 1 in matrix is identity matrix
        for(int i=0; i<sz; i++){
            mat[i][i]=1;
        }
    }

    Matrix operator*(Matrix other){
        Matrix res;
        for(int i=0; i<sz; i++)
            for(int j=0; j<sz; j++)
                for(int k=0; k<sz; k++){
                        res.mat[i][j] = (res.mat[i][j] + (mat[i][k] * other.mat[k][j]) % mod) % mod;
                }
        return res;

    }
};

// Matrix Exponentiaton O(log(n))

int fib(int n){
    if (n <= 2) return 1;

    n = n-2;

    Matrix res, m;
    res.identity();

    // m = {{1,1},{1,0}}
    m.mat[0][0] = m.mat[0][1] = m.mat[1][0] = 1;

    while(n){
        if(n&1) res = res * m;
        m = m*m;
        n /= 2;
    }

    // answer : (M^(n-2)*F(2))[0] 
    return (res.mat[0][0] + res.mat[0][1]) % mod;
}

void solve(){
    int n;
    cin >> n;
    cout << fib(n) << endl;
}

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    dp[0] = 0;
    dp[1] = 1;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}