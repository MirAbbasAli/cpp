#include<bits/stdc++.h>
using namespace std;
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n"
#define vi vector<int>
#define vvi vector<vector<int>>

int tsp(vvi &dist, int mask, int currentCity, int totalCity, vvi &dp){
    // Base Case
    // If all the nodes are visited, return cost from sourceCity to currentCity
    if (mask == (1<<totalCity)-1){
        return dist[currentCity][0];
    }

    if (dp[mask][currentCity] != -1){
        return dp[mask][currentCity];
    }

    int ans = INT_MAX;
    for(int visitCity=0; visitCity<totalCity; visitCity++){
        // Check if the city is not visited
        if (!(mask & (1<<visitCity))){
            mask = mask | (1<<visitCity);
            int subProb = dist[currentCity][visitCity] + tsp(dist, mask, visitCity, totalCity, dp);
            ans = min(ans, subProb);
        }
    }

    return dp[mask][currentCity] = ans;
}

void print2DArray(vvi &arr){
    for (int i=0; i<arr.size(); i++){
        for (int j=0; j<arr[0].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
void solve(){
    int m,n;
    cin >> m >> n;
    vvi dist(m, vi(n));
    vvi dp(1<<n, vi(n, -1));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int elem;
            cin >> elem;
            dist[i][j] = elem;
        }
    }
    cout << "Minimum cost: " << tsp(dist, 1, 0, n, dp) << "\n";
}
int main(){
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