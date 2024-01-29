#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int in_deg[100010];

vector<int> ans;
bool topo(int n){
    ans.clear();
    for(int i=1;i<=n;i++){
        if(!in_deg[i]){
            ans.emplace_back(i);
        }
    }
    for(int i=0;i<ans.size();i++){
        int u=ans[i];
        for(auto node:v[u]){
            in_deg[node]--;
            if(!in_deg[node]){
                ans.emplace_back(node);
            }
        }
    }
    return ans.size()==n;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].emplace_back(b);
        in_deg[b]++;
    }
    if(topo(n)){
        for(auto i:ans){
            printf("%d ",i);
        }
    }else{
        printf("IMPOSSIBLE");
    }
    return 0;
}