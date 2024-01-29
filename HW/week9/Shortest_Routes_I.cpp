#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> G[100010];
vector<long long> dijkstra(int S) {
    vector<long long> d(n, LONG_LONG_MAX);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for (auto [v, cost] : G[u]){
            if (d[v] > d[u] + cost) {
                d[v] = d[u] + cost;
                Q.emplace(d[v], v);
            }
        }
    }
    return d;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        G[a].emplace_back(b,c);
    }
    vector<long long> ans=dijkstra(0);
    for(auto i:ans){
        printf("%lld ",i);
    }
    printf("\n");
    return 0;
}