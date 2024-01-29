#include<bits/stdc++.h>
using namespace std;
int cnt[1000010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        cnt[num]++;
    }

    int maxgcd=1;
    for(int i=2;i<=1000000;i++){
        int nums=0;
        for(int j=i;j<=1000000;j+=i){
            nums+=cnt[j];
        }
        if(nums>=2){
            maxgcd=i;
        }
    }
    printf("%d\n",maxgcd);
    return 0;
}