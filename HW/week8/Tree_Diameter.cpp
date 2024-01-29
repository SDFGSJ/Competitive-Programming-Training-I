#include<bits/stdc++.h>
using namespace std;
int level[200010];
vector<int> tree[200010];
void dfs(int u, int parent = -1) {
    if(parent == -1) level[u] = 0;
    else level[u] = level[parent] + 1;

    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }
    dfs(1);
    int a = max_element(level+1,level+1+n)-level;
    dfs(a);
    int b = max_element(level+1,level+1+n)-level;
    printf("%d\n",level[b]);
    return 0;
}