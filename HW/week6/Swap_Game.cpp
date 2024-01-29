#include<bits/stdc++.h>
using namespace std;
queue<pair<string, int>> q;    //<grid, step>
unordered_set<string> visited;  //use unordered to prevent TLE
void myswap(string& grid, int step, int a, int b){
    swap(grid[a],grid[b]);
    if(!visited.count(grid)){
        visited.emplace(grid);
        q.emplace(grid,step+1);
    }
    swap(grid[a],grid[b]);
}
int main(){
    string s="0";   //initial state
    for(int i=1;i<=9;i++){
        int num;
        scanf("%d",&num);
        s+=('0'+num);
    }

    q.emplace(s,0);
    visited.emplace(s);
    while(!q.empty()){
        auto [grid, step] = q.front();q.pop();
        
        if(grid=="0123456789"){ //reach the goal
            printf("%d\n",step);
            break;
        }

        for(int i=1;i<=9;i++){  //only need to do up and right, or we would have duplicate actions
            if(i>=4){ //up
                myswap(grid,step,i,i-3);
            }
            if(i%3!=0){ //right
                myswap(grid,step,i,i+1);
            }
        }
    }
    return 0;
}
/*
2 1 3
7 5 9
8 4 6
=> "0213759846"
*/