

// url : https://cses.fi/problemset/task/1745


#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 998244353;
int32_t main(){
    int n;
    cin>>n;
    vector<int>value(n);
    int sm = 0;
    for(int i=0;i<n;i++) cin>>value[i], sm+=value[i];
    vector<bool>dp(sm+1,0);
    dp[0] = true;
    for(int i = 0; i<n; i++){
        for(int j = sm; j>=0; j--){
            if( j >= value[i] ) dp[j] = dp[j] | dp[j-value[i]];
        }
    }
    int cnt = 0;
    for (auto x  : dp ){
        if( x ) cnt++;
    }
    cout<<cnt-1<<endl;
    for(int i=1; i<=sm; i++){
        if(dp[i]) cout<<i<<" ";
    }
    cout<<endl;
}
