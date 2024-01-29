//solved
#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> s;   //<end,start>
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int l,r;
            scanf("%d%d",&l,&r);
            s.emplace(r,l);
        }else{
            int x;
            scanf("%d",&x);
            auto it=s.lower_bound(make_pair(x,0));
            if(it!=s.end() && it->second <= x && x <= it->first){
                printf("0\n");
            }else{
                printf("1\n");
            }
        }
    }
    return 0;
}