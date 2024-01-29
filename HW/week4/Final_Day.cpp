#include<bits/stdc++.h>
using namespace std;
int score[100010];  //score[i] = student i's total score, will be sorted
int tmp[100010];    //same as score[i] but in input order
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            int num;
            scanf("%d",&num);
            score[i]+=num;
        }
        tmp[i]=score[i];
    }
    sort(score,score+n,greater<>());
    for(int i=0;i<n;i++){
        //student i get 300, others get 0
        if(tmp[i]+300>=score[k-1]){ //student i is as good as student at rank k-th => i can be at top k
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}