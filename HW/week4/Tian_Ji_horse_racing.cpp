#include<bits/stdc++.h>
using namespace std;
long long a[10010],b[10010],c[10010];
int n,k;

template<class Ty, class FuncTy>
pair<Ty, Ty> binarySearch(Ty L, Ty R, FuncTy check){
    if(check(R) == false) return {R, R+1};
    if(check(L) == true) return {L-1, L};
    while(L+1 < R){
        Ty Mid = L + (R-L)/2;
        if(check(Mid)) R = Mid;
        else L = Mid;
    }
    return {L, R};
}

bool valid(int days){
    long long a_after[10010]={0};
    for(int i=0;i<n;i++){
        a_after[i]=a[i]+b[i]*days;
    }
    sort(a_after, a_after+n, greater<long long>());
    int cnt=0,idx=0;    //idx is for picking my horse
    for(int i=0;i<n;i++){
        if(a_after[idx]>c[i]){  //notice the idea here, try to get max # of wins
            cnt++;
            idx++;
        }
    }
    return cnt>=k;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&a[i],&b[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%lld",&c[i]);
        }
        sort(c,c+n,greater<long long>());

        int l=0,r=100000000;
        auto [a,b]=binarySearch(l,r,valid);
        if(a==r){
            printf("-1\n");
        }else{
            printf("%d\n",b);
        }
    }
    return 0;
}
/*
refs:
https://peienwu.com/sprout4-3/
https://oi.ototot.tw/2017/03/npsc-2011-f.html
*/