#include<bits/stdc++.h>
using namespace std;
vector<int> head,tail,front,back;
void print(int n){
    /*printf("head[]=");
    for(int i=1;i<=n;i++){
        printf("%d ",head[i]);
    }
    printf("\ntail[]=");
    for(int i=1;i<=n;i++){
        printf("%d ",tail[i]);
    }
    printf("\nfront[]=");
    for(int i=1;i<=n;i++){
        printf("%d ",front[i]);
    }
    printf("\nback[]=");
    for(int i=0;i<=n;i++){
        printf("%d ",back[i]);
    }
    printf("\n");*/

    for(int i=1;i<=n;i++){
        printf("#%d: ",i);
        int now=back[head[i]];
        while(now!=tail[i]){
            printf("%d ",now);
            now=back[now];
        }
        printf("\n");
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    head.resize(2*n+5);tail.resize(2*n+5);front.resize(2*n+5);back.resize(2*n+5);
    for(int i=1;i<=n;i++){
        head[i]=tail[i]=front[i]=back[i]=n+i;
        back[head[i]]=front[tail[i]]=i;
    }
    while(m--){
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        int afront=front[a],aback=back[a];
        int bfront=front[b],bback=back[b];
        if(t==0){   //person a goes to the back of person b
            if(back[b]==a){ //a is already at the back of b
                continue;
            }
            back[afront]=aback,front[aback]=afront; //link neighbors of a

            //b <=> a <=> b's back
            back[b]=a,front[a]=b;   //b <=> a
            back[a]=bback,front[bback]=a;   //a <=> b's back
        }else{  //everyone in queue a move to the back of queue b
            if(back[head[a]]==tail[a]){   //a is empty
                continue;
            }
            int start=back[head[a]],end=front[tail[a]]; //the start and end of the a-th queue
            int bend=front[tail[b]];

            back[head[a]]=tail[a],front[tail[a]]=head[a];   //a has no one, link a's head, tail together

            //b's end <=> start ... end <=> b's tail
            back[bend]=start,front[start]=bend; //b's end <=> start
            back[end]=tail[b],front[tail[b]]=end;   //end <=> b's tail
        }
    }
    print(n);
    return 0;
}
/*
head[i] = the head of i-th queue, dummy node n+i
tail[i] = the tail of i-th queue, dummy node n+i
front[i] = the person before i
back[i] = the person after i
ex. n=3, "<=>" is link
1: 4 <=> 1 <=> 4
2: 5 <=> 2 <=> 5
3: 6 <=> 3 <=> 6
*/