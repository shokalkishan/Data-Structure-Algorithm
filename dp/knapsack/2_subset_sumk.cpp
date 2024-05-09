#include<bits/stdc++.h>
using namespace std;
#define int long long 


// url : https://atcoder.jp/contests/abc321/tasks/abc321_f 


int32_t main(){
    int q, k ;
    cin >> q >> k;
    vector<int>dp(k+1,0);
    dp[0]=1;
    while(q--){
        char c; cin >> c;
        int x ; cin>>x;
        if(c == '+'){ 
            for(int i = k-x; i >= 0; i--) dp[i + x] += dp[i];
        }
        else{
            for(int i = 0; i+x <= k; i++) dp[i + x] -= dp[i];
        }
        cout << dp[k] << endl ;
    }

}