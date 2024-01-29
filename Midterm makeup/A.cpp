//solved
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n,greater<int>());
    long long sum=0;
    int ans=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum>=k){
            ans=i+1;
            break;
        }
    }
    printf("%d\n",ans);
    return 0;
}