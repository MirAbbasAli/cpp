#include<bits/stdc++.h>
using namespace std;
/*
// Wrong Solution
int maximumScore(int a, int b, int c) {
    vector<int> stones(3);
    stones[0] = a;
    stones[1] = b;
    stones[2] = c;
    sort(stones.begin(), stones.end());
    if (stones[0] + stones[1] > stones[2]) return stones[2];
    else return stones[0] + stones[1];
    
}
*/

int maximumScore(int a, int b, int c){
    int totalPile = a + b + c;
    int maxPile = max({a, b, c});
    return min(totalPile/2, totalPile - maxPile);
}

void solve(){
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    cout << maximumScore(a, b, c) << "\n";
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