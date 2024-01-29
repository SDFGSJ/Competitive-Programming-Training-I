#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e9+7;
vector<vector<int>>graph;
vector<vector<int>>dp;
void dfs(int src,int par){
    int white=1;
    int black=1;
    for(auto neigh:graph[src]){
        if(neigh!=par){
            dfs(neigh,src);
            white*=(dp[neigh][0]+dp[neigh][1])%mod;
            white%=mod;
            black*=(dp[neigh][0])%mod;
            black%=mod;
        }
    }
    dp[src][0]=white;
    dp[src][1]=black;
}

int32_t main(){
    int n;
    cin>>n;
    graph.resize(n+1);
    dp.resize(n+1,vector<int>(2));
    int cnt=n-1;
    while(cnt--){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);
    int ans=(dp[1][0]+dp[1][1])%mod;
    cout<<ans<<"\n";
}