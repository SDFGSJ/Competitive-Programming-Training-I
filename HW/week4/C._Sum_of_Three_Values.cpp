#include<bits/stdc++.h>
using namespace std;
map<int,vector<int>> m;    //<value,index>
int a[5010];
int main(){
    int n,target,i,j;
    bool haveans=false;
 
    scanf("%d%d",&n,&target);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        m[a[i]].push_back(i);
    }
 
    sort(a+1,a+1+n);
    for(i=1;i<=n && !haveans;i++){
        for(j=i+1;j<=n;j++){
            if(a[i]+a[j]>=target){  //optimization
                break;
            }
 
            int wanna_find = target-a[i]-a[j];
            if(binary_search(a+1+j, a+1+n, wanna_find)){
                if(a[i]==a[j] && a[i]==wanna_find){ //3 same
                    printf("%d %d %d\n", m[a[i]][0], m[a[i]][1], m[a[i]][2]);
                }else if(a[i]==a[j] && a[i]!=wanna_find){ //2 same,1 diff
                    printf("%d %d %d\n", m[a[i]][0], m[a[i]][1], m[wanna_find][0]);
                }else if(a[i]==wanna_find && a[i]!=a[j]){ //2 same,1 diff
                    printf("%d %d %d\n", m[a[i]][0], m[a[i]][1], m[a[j]][0]);
                }else if(a[j]==wanna_find && a[j]!=a[i]){ //2 same,1 diff
                    printf("%d %d %d\n", m[a[j]][0], m[a[j]][1], m[a[i]][0]);
                }else{  //3 diff
                    printf("%d %d %d\n", m[a[i]][0], m[a[j]][0], m[wanna_find][0]);
                }
                haveans=true;
                break;
            }
        }
    }
    if(!haveans){
        printf("IMPOSSIBLE\n");
    }
    return 0;
}