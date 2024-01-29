#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v;    //<duration, deadline>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int dura,dead;
        scanf("%d%d",&dura,&dead);
        v.emplace_back(dura,dead);
    }
 
    long long ans=0,now=0;
    sort(v.begin(),v.end());
    for(auto i:v){
        now+=i.first;
        ans+=i.second-now;
    }
    printf("%lld\n",ans);
    return 0;
}