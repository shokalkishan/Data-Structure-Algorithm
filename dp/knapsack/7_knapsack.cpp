#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define int long long


// url :  https://oj.uz/problem/view/NOI18_knapsack


void solve() {
    int s, n;
    cin >> s >> n;
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        int v, w, k;
        cin >> v >> w >> k;
        mp[w].push_back({v, k});
    }
    vector<int> dp(s + 1, 0);
    for (auto& w : mp) {
        int weight = w.first;
        auto& items = w.second;
        sort(items.begin(), items.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });
        for (int j = s; j >= 0; j--) {
            int pr = 0, wt = 0;
            for (auto& item : items) {
                int value = item.first;
                int count = item.second;
                for(int k=0;k<count;k++){
                    int rm = j - wt;
                    if (rm < weight) break;
                    wt+=weight;
                    pr+=value;
                    dp[j]=max(dp[j],dp[j-wt]+pr);
                }
            }        
        }
    }
    cout << dp[s] << endl;
}


int32_t main() {
    int t = 1; // cin >> t;
    while (t--) solve();
    return 0;
}
