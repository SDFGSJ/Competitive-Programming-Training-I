#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int NN=404;
LL D[NN][NN],S[NN];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>S[i],S[i]+=S[i-1],D[i][i]=0;
    for(int k=2;k<=n;k++)
        for(int l=1;l+k-1<=n;l++)
        {
            LL r=l+k-1,&d=D[l][r];
            d=1e18;
            for(int m=l;m<r;m++)
                d=min(d,S[r]-S[l-1]+D[l][m]+D[m+1][r]);
        }
    printf("%lld",D[1][n]);
    return 0;
}