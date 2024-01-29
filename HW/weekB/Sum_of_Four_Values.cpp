#include<bits/stdc++.h>
using namespace std;
int a[1010];
map<int,vector<pair<int,int>>> m;   //<sum,[<idx1, idx2>, <idx3, idx4>, ...]>
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    //calculate the sum of each pair
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            m[a[i]+a[j]].emplace_back(i+1,j+1);
        }
    }

    //find 2 pairs that sums to x
    for(auto item:m){
        int desired=x-item.first;
        auto it=m.find(desired);
        if(it!=m.end()){
            for(auto pair1:item.second){
                for(auto pair2:it->second){
                    if(pair1.first!=pair2.first && pair1.first!=pair2.second
                    && pair1.second!=pair2.first && pair1.second!=pair2.second){
                        printf("%d %d %d %d\n",pair1.first, pair1.second, pair2.first, pair2.second);
                        return 0;
                    }
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}