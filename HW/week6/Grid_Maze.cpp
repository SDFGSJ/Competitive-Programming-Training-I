#include<bits/stdc++.h>
using namespace std;
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
char grid[1010][1010];
int prevstep[1010][1010];
set<pair<int,int>> visited;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    pair<int,int> start,end;
    for(int i=0;i<n;i++){
        scanf("%s",grid[i]);
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                start={i,j};
            }
            if(grid[i][j]=='B'){
                end={i,j};
            }
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited.emplace(start);
    while(!q.empty()){
        pair<int,int> u=q.front();q.pop();
        for(int i=0;i<4;i++){
            int new_i=u.first+dx[i];
            int new_j=u.second+dy[i];

            if(0<=new_i && new_i<n && 0<=new_j && new_j<m
                && grid[new_i][new_j]!='#' && !visited.count({new_i,new_j})
            ){
                visited.emplace(new_i,new_j);
                prevstep[new_i][new_j]=i;
                q.emplace(new_i,new_j);
            }
        }
    }

    if(visited.count(end)){
        printf("YES\n");

        vector<int> steps;
        while(end!=start){
            int p=prevstep[end.first][end.second];
            steps.push_back(p);
            end=make_pair(end.first-dx[p], end.second-dy[p]);
        }
        reverse(steps.begin(), steps.end());

        printf("%ld\n",steps.size());
        for(int idx:steps){
            printf("%c","URDL"[idx]);
        }
    }else{
        printf("NO\n");
    }
    return 0;
}
/*
refs:
https://www.rishabhxchoudhary.study/blog/cses-graph-editorals
https://ideone.com/GA1BwS
https://github.com/Abhishek0706/Solutions/blob/main/cses/labyrinth.cpp
https://cses.fi/paste/947cb48d6c7c1ee227bdf9/
*/