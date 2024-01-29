#include <bits/stdc++.h>
#define int long long
#define double long double
#define pii pair<int, int>
#define N 200005
#define INF LONG_LONG_MAX
#define x first
#define y second
#define all(a) a.begin(),a.end()
#define IOS ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
string str;
int dx[4] = {1,0,-1,0},dy[4] = {0,1,0,-1};
bool vis[9][9];
int ans = 0;

void solve(int x,int y,int s){
    if(x < 1 || x > 7 || y < 1 || y > 7 || vis[x][y])return;
    if(x == 1 && y == 7 && s < 48)return;
    if(vis[x-1][y] && vis[x+1][y] && !vis[x][y+1] && !vis[x][y-1])return;
    if(!vis[x-1][y] && !vis[x+1][y] && vis[x][y+1] && vis[x][y-1])return;
    if(s == 48){
        ans++;
        return;
    }
    vis[x][y] = 1;
    int ans = 0;
    if(str[s] == 'L')solve(x - 1, y, s + 1);
    if(str[s] == 'R')solve(x + 1, y, s + 1);
    if(str[s] == 'U')solve(x, y - 1, s + 1);
    if(str[s] == 'D')solve(x, y + 1, s + 1);
    if(str[s] == '?'){
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i],ny = y + dy[i];
            solve(nx,ny,s+1);
        }
    }
    vis[x][y] = 0;
}

signed main(){
    IOS;
    cin>>str;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=7;i++){
        vis[i][0] = 1;
        vis[8][i] = 1;
        vis[i][8] = 1;
        vis[0][i] = 1;
    }
    solve(1,1,0);
    cout<<ans<<"\n";
}
/*
refs:
https://usaco.guide/problems/cses-1625-grid-paths/solution
https://peienwu.com/cses1-19/
*/