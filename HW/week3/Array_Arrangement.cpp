#include<bits/stdc++.h>
using namespace std;
vector<bool> used;
vector<pair<char,int>> v;   //<op, num>
deque<int> front,back;
void print(int n){
    for(int i=0;i<front.size();i++){
        printf("%d ",front[i]);
    }
    for(int i=1;i<=n;i++){  //unmodified numbers
        if(!used[i]){
            printf("%d ",i);
        }
    }
    for(int i=0;i<back.size();i++){
        printf("%d ",back[i]);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        front.clear(),back.clear();

        int n,q;
        scanf("%d%d",&n,&q);

        used.resize(n+1);   //index=1~n
        fill(used.begin(),used.end(),false);

        v.resize(q);
        for(int i=0;i<q;i++){
            getchar();
            scanf("%c%d",&v[i].first,&v[i].second);
        }

        for(int i=v.size()-1;i>=0;i--){ //parse from the back
            if(!used[v[i].second]){ // not yet used
                if(v[i].first=='H'){
                    front.push_back(v[i].second);
                }else{
                    back.push_front(v[i].second);
                }
                used[v[i].second]=true;
            }
        }
        print(n);
    }
    return 0;
}