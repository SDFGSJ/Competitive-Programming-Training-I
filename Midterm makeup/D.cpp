//solved
#include<bits/stdc++.h>
using namespace std;
int c[100010],n,m;

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

bool valid(int time){
    long long cost=0;
    for(int i=0;i<n;i++){
        cost+=(c[i]/time);
        if(c[i]%time){
            cost++;
        }
    }
    return cost<=m;
}

int main(){
    int l=1,r=0;

    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        r=max(r,c[i]);
    }

    auto [a,b] = binarySearch(l,r,valid);
    printf("%d\n",b);
    return 0;
}