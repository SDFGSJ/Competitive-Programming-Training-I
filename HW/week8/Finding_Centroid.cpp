#include<bits/stdc++.h>
using namespace std;
vector<int> tree[200010];
vector<int> mysize;
int n, ans = -1;
void dfs(int u, int parent = -1) {
    mysize[u] = 1;
    int max_son_size = 0;
    for (auto v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u);
        mysize[u] += mysize[v];
        max_son_size = max(max_son_size, mysize[v]);
    }
    max_son_size = max(max_son_size, n - mysize[u]);
    if (max_son_size <= n / 2) ans = u;
}
int main(){
    scanf("%d",&n);
    mysize.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}