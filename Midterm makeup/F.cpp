#include<bits/stdc++.h>
using namespace std;
int cnt[25][25];
int grid[25][25];
long long ans;
int n,m,cnt_total;
pair<int,int> dxy[9]={
    {-1,-1}, {-1,0}, {-1,1},
    {0,-1}, {0,0}, {0,1},
    {1,-1}, {1,0}, {1,1},
    };
bool inside_grid(int r,int c){
    return (0<=r && r<n && 0<=c && c<m);
}
void printboard(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}
bool neighbor_has0(int r,int c){
    bool has0=false;
    for(auto [di,dj]:dxy){
        if(inside_grid(r+di,c+dj) && cnt[r+di][c+dj]==0){
            has0=true;
        }
    }
    return has0;
}
void dfs(int idx, int grid_sum){
    int r=idx/m, c=idx%m;

    if(idx==n*m){
        if(grid_sum==cnt_total && cnt_total!=0){
            ans++;
        }
        return;
    }

    if(inside_grid(r-1,c-2) && grid[r-1][c-2]!=cnt[r-1][c-2]){
        return;
    }

    if(cnt[r][c]==0 || neighbor_has0(r,c)){ //cant put
        dfs(idx+1,grid_sum);
    }else{
        bool canput=true;
        for(auto [di,dj]:dxy){
            if(inside_grid(r+di,c+dj) && grid[r+di][c+dj]+1>cnt[r+di][c+dj]){
                canput=false;
            }
        }

        //dont put
        dfs(idx+1,grid_sum);

        if(canput){
            //put
            int tmp=0;
            for(auto [di,dj]:dxy){
                if(inside_grid(r+di,c+dj)){
                    grid[r+di][c+dj]+=1;
                    tmp++;
                }
            }
            dfs(idx+1,grid_sum+tmp);
            for(auto [di,dj]:dxy){
                if(inside_grid(r+di,c+dj)){
                    grid[r+di][c+dj]-=1;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&cnt[i][j]);
            cnt_total+=cnt[i][j];
        }
    }
    dfs(0,0);
    printf("%lld\n",ans);
    return 0;
}