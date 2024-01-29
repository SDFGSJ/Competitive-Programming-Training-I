#include<bits/stdc++.h>
using namespace std;
int d[55];
queue<pair<int,int>> q; //<position, step>
bool visited[2000010];
int main(){
    int n,x,k;
    scanf("%d%d%d",&n,&x,&k);
    for(int i=0;i<k;i++){
        scanf("%d",&d[i]);
    }

    int step=0;
    visited[1]=true;
    q.emplace(1,step);
    while(!q.empty()){
        auto [now, s] = q.front();q.pop();
        if(now==x){
            printf("%d\n",s);
            return 0;
        }

        for(int i=0;i<k;i++){
            long long tmp = 1ll*now*d[i];
            if(tmp>n){
                tmp=(tmp-1)%n+1;
            }

            if(!visited[tmp]){
                q.emplace(tmp,s+1);
                visited[tmp]=true;
            }
        }
        step++;
    }
    printf("I LOVE TSING HUA\n");
    return 0;
}