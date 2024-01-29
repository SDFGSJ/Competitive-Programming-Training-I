#include<bits/stdc++.h>
using namespace std;
priority_queue<int> l;  //max heap(numbers that < median)
priority_queue<int,vector<int>,greater<int>> r;   //min heap(numbers that >= median)
int main(){
    int n;
    scanf("%d",&n);

    int median=0;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);

        //push the num into heap
        if(num>=median){
            r.push(num);
        }else{
            l.push(num);
        }

        //balance the size of 2 heaps
        if(r.size()>l.size()+1){    //r has 2 more elements than l
            int rtop=r.top();r.pop();   //move the smallest num in r to l
            l.emplace(rtop);
        }else if(r.size()+1<l.size()){  //l has 2 more elements than r
            int ltop=l.top();l.pop();   //move the largest num in l to r
            r.emplace(ltop);
        }

        //the ans depends on the size of 2 heaps
        if(l.size()<r.size()){
            printf("%d ",r.top());
            median=r.top();
        }else{
            printf("%d ",l.top());
            median=l.top();
        }
    }
    return 0;
}