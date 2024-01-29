#include<bits/stdc++.h>
using namespace std;
string str;
int grid[9][9];
int row[9],col[9],subgrid[3][3];    // row[i]=00111110000 => number 4~8 in i-th row is used
const int MASK=(1<<10)-2;   // 01111111110
int lowbit(int x){
    return x & -x;
}
/*bool illegal(int r, int c, int num){
    // unavailable set & num => return true if num is unavailable
    return (row[r] | col[c] | subgrid[r/3][c/3]) & num;
}*/
void update(int r, int c, int num){
    row[r]^=num;
    col[c]^=num;
    subgrid[r/3][c/3]^=num;
}
void parse(){   // parse str into grid
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(isdigit(str[i*9+j])){
                grid[i][j] = 1 << (str[i*9+j]-'0');
                update(i,j,grid[i][j]);
            }else{
                grid[i][j] = 0;
            }
        }
    }
}
void print(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<__lg(grid[i][j]);
        }
    }
    cout<<'\n';
}
bool dfs(int idx){  // numbered every grid from 0~80
    if(idx==81){
        return true;
    }

    int r=idx/9, c=idx%9;
    if(grid[r][c]){ // if this grid has a number
        return dfs(idx+1); // fill the next grid
    }

    int S=MASK & ~(row[r] | col[c] | subgrid[r/3][c/3]);    // set of available numbers
    for(int num=0;S;S^=num){
        num=lowbit(S);  // take smallest num from available set

        grid[r][c]=num;
        update(r,c,num);
        if(dfs(idx+1)){
            return true;
        }
        update(r,c,num);
        
    }
    grid[r][c]=0;   // recover after recursion
    return false;
}
bool check(){
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    memset(subgrid,0,sizeof(subgrid));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            update(i,j,grid[i][j]);
        }
    }
    for(int i=0;i<9;i++){
        if(row[i]!=MASK || col[i]!=MASK || subgrid[i/3][i%3]!=MASK){
            return false;
        }
    }
    return true;
}
int main(){
    while(1){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(subgrid,0,sizeof(subgrid));
        cin>>str;
        if(str=="end"){
            break;
        }
        parse();
        dfs(0);
        if(check()){    // check after fill in all the numebrs
            print();
        }else{
            printf("No solution.\n");
        }
    }
    return 0;
}