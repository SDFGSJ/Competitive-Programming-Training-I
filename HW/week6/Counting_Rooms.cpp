#include<bits/stdc++.h>
using namespace std;
char grid[1010][1010];
bool vis[1010][1010];
int di[4]={-1,0,1,0};
int dj[4]={0,1,0,-1};
int main(){
    int n,m,i,j,k;
    int room=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%s",grid[i]);
    }
 
 
    queue<pair<int,int>> q;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(grid[i][j]!='#' && !vis[i][j]){
                vis[i][j]=true;
                q.emplace(i,j);
                while(!q.empty()){
                    int x,y;
                    tie(x,y)=q.front();
                    q.pop();
                    //printf("(%d,%d)\n",x,y);
                    for(k=0;k<4;k++){
                        int newi=x+di[k], newj=y+dj[k];
 
                        if(0<=newi && newi<n && 0<=newj && newj<m && grid[newi][newj]!='#' && !vis[newi][newj]){
                            vis[newi][newj]=true;
                            q.emplace(newi,newj);
                        }
                    }
                }
                room++;
            }
        }
    }
 
    printf("%d\n",room);
    return 0;
}