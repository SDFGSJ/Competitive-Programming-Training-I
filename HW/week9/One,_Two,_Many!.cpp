#include<bits/stdc++.h>
using namespace std;
int color[100010];
vector<int> g[100010];
bool visited[100010];
bool dfs(int u, int c = 1) {
    visited[u]=true;
    if (color[u])
        return color[u] == c;
    color[u] = c;
    for (auto v : g[u])
        if (!dfs(v, c * -1))
            return false;
    return true;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    bool ok=true;
    for(int i=1;i<=n;i++){  //many componenets
        if(!visited[i]){
            ok &= dfs(i);
        }
    }
    if(ok){
        for(int i=1;i<=n;i++){
            if(i!=1){
                printf(" ");
            }
            if(color[i]==1){
                printf("1");
            }else{
                printf("2");
            }
        }
        printf("\n");
    }else{
        printf("MANY\n");
    }
    return 0;
}