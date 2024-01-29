#include<bits/stdc++.h>
using namespace std;
char m[10][10];
int ans,q[10];
bool valid(int row,int col){
    int i;
    for(i=0;i<row;i++){
        if(q[i]==col || q[i]-col==row-i || q[i]-col==i-row){
            return false;
        }
    }
    return true;
}
void place(int row){
    if(row==8){
        ans++;
        return;
    }
 
    int i;
    for(i=0;i<8;i++){
        if(m[row][i]!='*' && valid(row,i)){
            q[row]=i;
            place(row+1);
        }
    }
}
int main(){
    int i;
    for(i=0;i<8;i++){
        scanf("%s",m[i]);
    }
    place(0);
    printf("%d\n",ans);
    return 0;
}