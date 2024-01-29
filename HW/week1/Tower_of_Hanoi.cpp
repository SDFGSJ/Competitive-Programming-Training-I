#include<bits/stdc++.h>
using namespace std;
void hanoi(int n,int from,int buffer,int to){
    if(n==1){
        printf("%d %d\n",from,to);
        return;
    }
 
    hanoi(n-1,from,to,buffer);
    printf("%d %d\n",from,to);
    hanoi(n-1,buffer,from,to);
 
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d\n",(int)pow(2,n)-1);
    hanoi(n,1,2,3);
    return 0;
}