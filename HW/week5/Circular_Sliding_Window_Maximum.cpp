#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        v.emplace_back(num);
    }
    for(int i=0;i<k-1;i++){ //circular trick, push the first k-1 nums to the back of v
        v.emplace_back(v[i]);
    }
    
    deque<int> dq;  //stores the idx of v, idx is increasing, v[idx] is decreasing
    for(int i=0;i<v.size();i++){
        while(dq.size() && dq.front()<=i-k){    //remove out of bound idx
            dq.pop_front();
        }

        while(dq.size() && v[dq.back()]<v[i]){  //remove nums to keep the deque v[idx] in decresing order
            dq.pop_back();
        }

        dq.emplace_back(i); //push idx

        if(i>=k-1){ //condition to print the ans(when sliding window size=k)
            printf("%d ",v[dq.front()]);
        }
    }
    return 0;
}