#include <bits/stdc++.h>
#define F(n) Fi(i,n)
#define Fi(i,n) for(int i=0;i<n;i++)
#define N 1000010
#define LL long long
using namespace std;
LL ST[N],SUM[N];
int t,l,r,ans,n,st,R[N],L[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        F(n){
            cin>>SUM[i+1];
            SUM[i+1]+=SUM[i];
        }
        st=0;
        F(n+1){
            while(st&&SUM[ST[st-1]]<=SUM[i])R[ST[--st]]=i;
            ST[st++]=i;
        }
        while(st--)R[ST[st]]=n+1;
        st=0;
        F(n+1){
            while(st&&SUM[ST[st-1]]>SUM[i])L[ST[--st]]=i;
            ST[st++]=i;
        }
        while(st--)L[ST[st]]=n+1;
        l=r=ans=0;
        while(l<n){
            while(r<=n&&R[r]<L[l])r=R[r];
            ans=max(ans,r-l);
            l=r=r+1;
        }
        cout<<ans<<'\n';
    }
}
/*
ref:
https://www.chino.taipei/code-2016-1205TIOJ-1841-%E5%A5%BD%EF%BC%8E%E5%82%B3%E5%9B%89%EF%BC%81-Nice-Boat%EF%BC%81/
*/