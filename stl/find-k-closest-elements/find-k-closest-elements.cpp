#include<bits/stdc++.h>
using namespace std;
#define print(arr) for(auto x: arr) cout << x << " "; cout << "\n"


vector<int> findClosestElements(vector<int> arr, int k, int x) {
    // Comparator
    auto com = [x](int a, int b){
        if (abs(a-x) < abs(b-x)) return true;
        return a < b;
    };
    vector<int> closestArr(arr);
    sort(closestArr.begin(), closestArr.end(), com);
    // print(closestArr);

    vector<int> newArr(closestArr.begin(), closestArr.begin() + k);
    sort(newArr.begin(), newArr.end());

    return newArr;

}

void solve(){
    int n, elem, k, x;
    vector<int> arr;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> elem;
        arr.push_back(elem);
    }


    cin >> k;
    cin >> x;

    print(findClosestElements(arr, k, x));
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