

// url : https://cses.fi/problemset/task/1158


#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 998244353;
int32_t main(){
    int n, x;
    cin>>n>>x;
    vector<int>price(n),page(n),dp(x+1,0);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>page[i];
    
    for(int i = 0; i<n; i++){
        for(int j = x; j>=0; j--){
            if( j >= price[i]) dp[j] = max(dp[j], dp[j-price[i]] + page[i]);
        }
    }
    cout<< dp[x] <<endl;
}