#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, cost;
    bool operator<(const Edge &other) const {
    return cost < other.cost;
    }
};
//union_find_tree
struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};
vector<Edge> E;
bool haveans=true;
long long MST(int n){
    sort(E.begin(),E.end());
    union_find DS(n);
    long long ans=0;
    int cnt=0;
    for(auto& e:E){
        if(DS.same(e.u, e.v)){
            continue;
        }
        DS.unite(e.u, e.v);
        ans += e.cost;
        cnt++;
    }
    if(cnt<n-1){
        printf("IMPOSSIBLE\n");
        haveans=false;
    }
    return ans;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    E.resize(m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        E[i].u=a,E[i].v=b,E[i].cost=c;
    }
    long long ans=MST(n);
    if(haveans){
        printf("%lld\n",ans);
    }
    return 0;
}