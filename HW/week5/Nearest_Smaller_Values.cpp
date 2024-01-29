#include<bits/stdc++.h>
using namespace std;
int a[200010];
stack<pair<int,int>> s;   //monotonic stack <val,idx> with val ascending
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top().first>=a[i]){   //remove elements
            s.pop();
        }

        if(s.empty()){  //top is the ans
            printf("0 ");
        }else{
            printf("%d ",s.top().second);
        }

        s.emplace(a[i],i+1);    //push the current number
    }
    return 0;
}