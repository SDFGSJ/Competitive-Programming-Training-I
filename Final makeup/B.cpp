#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

vector<vector<pair<int,long long>>> G;
int n,m;
long long k;

vector<long long> dijkstra(const vector<vector<pair<int, long long>>> &G, int S, long long day) {
    int n = G.size(); // vertex index from 0 to n-1
    vector<long long> d(n, INF);
    using QueuePair = pair<long long, int>;
    priority_queue<QueuePair, vector<QueuePair>, greater<QueuePair>> Q;
    d[S] = 0; // starting point set to 0
    Q.emplace(d[S], S);
    while (Q.size()) {
        auto [u_dis, u] = Q.top();
        Q.pop();
        if (d[u] < u_dis) continue;
        for (auto [v, cost] : G[u])
            if (d[v] > d[u] + max(cost-day, 1ll)) {
                d[v] = d[u] + max(cost-day, 1ll);
                Q.emplace(d[v], v);
            }
    }
    return d;
}
template<class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check){
    //if(check(R) == false) return {R, R+1};
    //if(check(L) == true) return {L-1, L};
    while(L+1 < R){
        Ty Mid = L + (R-L)/2;   //enumerate days

        auto result=dijkstra(G, 0, Mid);

        if(check(result)) R = Mid;
        else L = Mid;
    }
    return {L, R};
}
bool valid(const vector<long long>& d){
    return d[n-1]<=k;
}
int main(){
    scanf("%d%d%lld",&n,&m,&k);
    G.assign(n+1,{});
    for(int i=0;i<m;i++){
        int x,y;
        long long w;
        scanf("%d%d%lld",&x,&y,&w);
        G[x].emplace_back(y,w);
        G[y].emplace_back(x,w);
    }

    long long l=0ll, r=1000000000000000000ll;
    auto [L,R] = binarySearch(l,r,valid);
    printf("%lld\n",R);
    return 0;
}