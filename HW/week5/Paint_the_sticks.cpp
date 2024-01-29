#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        vector<int> v;
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            v.emplace_back(num);
        }
        
        v.emplace_back(0);  // in order to delete all turing points in stack
        stack<pair<int,int>> s; //record the turning point <height, corner idx>
        long long ans=0;
        for(int i=0;i<v.size();i++){
            int corner=i;
            while(s.size() && s.top().first >= v[i]){
                corner=s.top().second;
                ans=max(ans, 1ll*(i-corner)*s.top().first);
                s.pop();
            }
            s.emplace(v[i],corner);
        }
        printf("%lld\n",ans);
    }
    return 0;
}