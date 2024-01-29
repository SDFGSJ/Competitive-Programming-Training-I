#include<bits/stdc++.h>
using namespace std;
int n,m,a[25],ans[25];
void print(){
    int i;
    for(i=0;i<m;i++){
        if(i==0){
            printf("%d",ans[i]);
        }else{
            printf(" %d",ans[i]);
        }
    }
    printf("\n");
}
void dfs(int i,int k){
    if(k==m){   // already take enough numbers
        print();
        return;
    }

    for(int j=i;j<n;j++){
        ans[k]=a[j];
        dfs(j+1,k+1);    // the idx of deeper level starts from j+1, not i+1
        /*if the loop of this lv is in mid way && deeper lv idx starts from i+1(but not j+1)
        then it would take duplicate numbers*/
    }
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    return 0;
}