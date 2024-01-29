#include<bits/stdc++.h>
using namespace std;
vector<pair<int,long long>> G[100010];
long long dp[100010][2];
long long dfs(int u, int pick, int parent = 0){
    if(dp[u][pick] != -1){
        return dp[u][pick];
    }

    long long result=0ll;
    for(auto [v,w]:G[u]){
        if(v!=parent){
            result += max(dfs(v,0,u), dfs(v,1,u));
        }
    }

    if(pick==0){
        dp[u][pick]=result;
    }else{
        for(auto [v,w]:G[u]){
            if(v!=parent){
                dp[u][pick] = max(dp[u][pick], result-max(dfs(v,0,u), dfs(v,1,u)) + w + dfs(v,0,u));
            }
        }
    }
    return dp[u][pick];
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v;
        long long w;
        scanf("%d%d%lld",&u,&v,&w);
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=dp[i][1]=-1;
    }
    printf("%lld\n",max(dfs(1, 0), dfs(1, 1)));
    return 0;
}
/*
dp[i][0]=max score of subtree rooted at i, dont choose any edge (i, i's child)
dp[i][1]=max score of subtree rooted at i, choose exactly 1 edge (i, i's child)

dp[u][0] = sum(max{dp[v][0], dp[v][1]}) v = u's child

dp[u][1] = w + dp[x][0] + sum(max({dp[v][0], dp[v][1]}))
x = one of u's child
w = weight of edge (u,x)
v = u's child except x
*/