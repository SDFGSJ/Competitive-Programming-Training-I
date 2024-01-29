#include<bits/stdc++.h>
using namespace std;
void UpRing(int n);
void DownRing(int n){   // want to take n-th ring down
    if(n>2) DownRing(n-2);  // ring 1~n-2 have to be moved out first
    printf("Move ring %d out\n",n); // take down n-th ring
    if(n>2) UpRing(n-2);    // put ring 1~n-2 back
    if(n>1) DownRing(n-1);  // the problem becomes smaller(solve n-1 rings)
}
void UpRing(int n){ // want to move n-th ring up
    if(n>1) UpRing(n-1);    // (n-1)-th ring must be on the stick
    if(n>2) DownRing(n-2);  // make sure that ring 1~n-2 have been taken down
    printf("Move ring %d in\n",n);  // move n-th ring up
    if(n>2) UpRing(n-2);    // the problem becomes smaller(solve n-2 rings)
}
int main(){
    int n;
    scanf("%d",&n);
    DownRing(n);
    //UpRing(9);
    return 0;
}
// ref:https://developer.aliyun.com/article/708738