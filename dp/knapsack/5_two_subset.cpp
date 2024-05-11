#include<bits/stdc++.h>
using namespace std;
#define int long long

// url : https://cses.fi/problemset/task/1093/

int32_t main(){

    int n; cin>>n;
    int sm = ((n+1)*n)/2;
    if(sm&1) cout<< 0 <<endl;
    else{
        int mod = 1e9+7;
        sm = sm/2;
        vector<int>dp(sm+1,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=sm ;j>=i;j--){
                dp[j] = (dp[j]+dp[j-i])%mod;
            }
        }
        cout<<dp[sm]<<endl;
    }

}