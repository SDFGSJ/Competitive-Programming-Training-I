#include<bits/stdc++.h>
using namespace std;
int n,k,a[200010];
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
bool valid(long long mid){
    int groups = 1;   //at least 1 subarray
    long long sum = 0;
    for(int i=0;i<n;i++){
        if(sum + a[i] > mid){   //sum exceeds, form a new subarray
            groups++;
            sum = 0;  //reset sum
        }
        sum += a[i];
    }
    return groups <= k;
}
int main(){
    scanf("%d%d",&n,&k);

    long long l=0, r=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        l = max(l, 1ll*a[i]);   //lower bound is the max element in array a
        r += a[i];  //upper bound is the sum of array a
    }
    
    long long A, B;
    tie(A, B) = binarySearch(l, r, valid);
    printf("%lld\n",B);
    return 0;
}
/*
ref
https://www.youtube.com/watch?v=1fPLrKOv6rE
https://www.youtube.com/watch?v=nai96X4ZsJg

check() would be like: [F F F T T T T], false at the front, true at the back
special cases:
[F F F F F] or [T T T T T]
*/