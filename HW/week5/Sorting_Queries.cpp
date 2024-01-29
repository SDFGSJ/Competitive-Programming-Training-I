#include<bits/stdc++.h>
using namespace std;
queue<int> q;
priority_queue<int,vector<int>,greater<int>> pq;
int main(){
    int query;
    scanf("%d",&query);
    while(query--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            q.push(x);
        }else if(op==2){
            if(!pq.empty()){
                printf("%d\n",pq.top());
                pq.pop();
            }else{
                printf("%d\n",q.front());
                q.pop();
            }
        }else{
            while(!q.empty()){
                pq.push(q.front());q.pop();
            }
        }
    }
    return 0;
}