#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> G[100010];
int prede[100010],len[100010];
bool visited[100010];
void bfs(int u){
    queue<int> q;
    q.emplace(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(visited[u]){
            continue;
        }
        visited[u]=true;
        for(auto [v,l]:G[u]){
            q.emplace(v);
            if(prede[v]==-1){
                prede[v]=u;
            }
            if(len[v]==-1){
                len[v]=l;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        G[u].emplace_back(v,l);
        G[v].emplace_back(u,l);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=n;i++){
            visited[i]=false;
            prede[i]=len[i]=-1;
        }
        prede[x]=0;
        bfs(x);

        int now=y,ans=-1;
        while(now!=x){
            ans=max(ans,len[now]);
            now=prede[now];
        }
        printf("%d\n",ans);
    }
    return 0;
}