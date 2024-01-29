#include<bits/stdc++.h>
using namespace std;
int a[200010];
long long prefix[200010];
map<long long,vector<int>> m;   //<num,array of idx>
int main(){
    int n,target,i;
    long long cnt=0;
    scanf("%d%d",&n,&target);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
 
    //calculate prefix sum
    for(i=0;i<n;i++){
        if(i==0){
            prefix[i]=a[i];
        }else{
            prefix[i]=prefix[i-1]+a[i];
        }
        m[prefix[i]].push_back(i);
    }
 
 
    for(i=0;i<n;i++){
        //if the num we want is in the map
        if(m.count(prefix[i]+target)){
            vector<int>& tmp=m[prefix[i]+target];   //use reference to avoid TLE
            cnt+=distance(upper_bound(tmp.begin(),tmp.end(),i), tmp.end()); //count how many idx that is > i
        }
 
        //if the prefix sum itself == target
        if(prefix[i]==target){
            cnt++;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}