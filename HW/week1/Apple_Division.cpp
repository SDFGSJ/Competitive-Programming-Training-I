#include<bits/stdc++.h>
using namespace std;
int n,a[25];
long long total,sum,ans=1e16;
void dfs(int i){
    if(i==n){
        ans = min(ans, abs((total-sum) - sum));
        return;
    }

    dfs(i+1);   // dont choose

    sum+=a[i];  // choose
    dfs(i+1);
    sum-=a[i];
}
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        total+=a[i];
    }
    dfs(0);
    printf("%lld\n",ans);
    return 0;
}