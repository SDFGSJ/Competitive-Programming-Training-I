#include<bits/stdc++.h>
using namespace std;
long long dp[505][505]; //Floyd-Warshall
int main(){
    int i,j,k;
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            dp[i][j]=1e16;  //default to INF
        }
    }
    for(i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(c<dp[a][b]){ //beware of multi edge
            dp[a][b]=dp[b][a]=c;
        }
    }

    //1-indexed
    for(i=1;i<=n;i++){  //self to self = 0
        dp[i][i]=0;
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    for(i=0;i<q;i++){
        int from,to;
        scanf("%d%d",&from,&to);
        if(dp[from][to]>=1e16){
            printf("-1\n");
        }else{
            printf("%lld\n",dp[from][to]);
        }
    }
    return 0;
}