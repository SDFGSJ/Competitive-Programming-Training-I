#include<bits/stdc++.h>
using namespace std;
int a[105];
bool dp[105][1000010];
/*
dp[i][j]=1 <=> select some elements in 1~i, can have sum=j
*/
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    //can construct weight=0
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }

    //it is impossible to have sum>=1 when not choosing any element
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];    //dont choose element i
            if(j-a[i-1]>=0){    //choose element i
                dp[i][j] |= dp[i-1][j-a[i-1]];
            }
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<=sum;i++){
        if(dp[n][i]){   //sum=i is possible
            ans = min(ans, abs(i - (sum-i)));
        }
    }
    printf("%d\n",ans);
    return 0;
}