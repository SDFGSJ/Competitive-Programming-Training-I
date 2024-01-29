#include<bits/stdc++.h>
using namespace std;
int act[100010][3], dp[100010][3];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        act[i][0]=a,act[i][1]=b,act[i][2]=c;
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=act[i][0]+max(dp[i-1][1], dp[i-1][2]);
        dp[i][1]=act[i][1]+max(dp[i-1][0], dp[i-1][2]);
        dp[i][2]=act[i][2]+max(dp[i-1][0], dp[i-1][1]);
    }
    printf("%d\n",max({dp[n][0], dp[n][1], dp[n][2]}));
    return 0;
}
/*
dp[i][0]= max happiness that Taro can get as of day i, and do activity 0 on day i
*/