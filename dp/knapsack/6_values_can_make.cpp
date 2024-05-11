#include<bits/stdc++.h>
using namespace std;
#define int long long

// url : https://codeforces.com/contest/687/problem/C

int32_t main(){

    int n,k; cin>>n>>k;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>>prev(k+1,vector<int>(k+1,0)),curr(k+1,vector<int>(k+1,0));
    prev[0][0]=1;
    for(int i=0;i<n;i++){
        for(int sm=0;sm<=k;sm++){
            for(int p=0;p<=k;p++){
                curr[sm][p] = prev[sm][p];
                if(sm>=arr[i]) curr[sm][p] |= prev[sm-arr[i]][p];
                if(sm>=arr[i] && p>=arr[i])curr[sm][p]|=prev[sm-arr[i]][p-arr[i]] ;
            }
        }
        prev = curr;
    }
    int cnt = 0;
    for( int i = 0;i<=k;i++){
        if(curr[k][i]) cnt++;
    }
    cout<<cnt<<endl;
    for( int i = 0;i<=k;i++){
        if(curr[k][i]) cout<<i<<" ";
    }
    cout<<endl;
}