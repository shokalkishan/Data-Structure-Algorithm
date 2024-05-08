#include <iostream>
#include <vector>
using namespace std;

int coin_combination_ordered_rec(vector<int>& arr, int ind, int sm, int x, vector<vector<int>>& dp) {
    if (sm == x && ind == arr.size())
        return 1;
    if (sm > x || ind == arr.size())
        return 0;
    if (dp[ind][sm] != -1)
        return dp[ind][sm];
    int include = coin_combination_ordered_rec(arr, ind, sm + arr[ind], x, dp);
    int exclude = coin_combination_ordered_rec(arr, ind + 1, sm, x, dp);
    dp[ind][sm] = (include + exclude) % 1000000007;
    return dp[ind][sm];
}

int coin_combination_ordered(vector<int>& arr, int x) {
    int mod = 1000000007;
    int n = arr.size();
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <= x; ++j) {
            dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
        }
    }
    return dp[x];
}

int coin_combination_unordered_rec(vector<int>& arr, int ind, int sm, int x, vector<vector<int>>& dp) {
    if (sm == x && ind == arr.size())
        return 1;
    if (sm > x || ind == arr.size())
        return 0;
    if (dp[ind][sm] != -1)
        return dp[ind][sm];
    int include = coin_combination_unordered_rec(arr, 0, sm + arr[ind], x, dp);
    int exclude = coin_combination_unordered_rec(arr, ind + 1, sm, x, dp);
    dp[ind][sm] = (include + exclude) % 1000000007;
    return dp[ind][sm];
}
int coin_combination_unordered(vector<int>& arr, int x) {
    int mod = 1000000007;
    int n = arr.size();
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= x; ++j) {
        for (int i = 0; i < n; ++i) {
            if(j >= arr[i])dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
        }
    }
    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
    cout << coin_combination_unordered(arr, x) << endl;
    return 0;
}
