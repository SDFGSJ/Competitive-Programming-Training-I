#include<bits/stdc++.h>
using namespace std;
vector<tuple<long long, int, int, vector<int>>> v;  //<sum, max, people, quan>
bool cmp(const tuple<long long, int, int, vector<int>>& a, const tuple<long long, int, int, vector<int>>& b){
    if(get<0>(a) != get<0>(b)){ //sum
        return get<0>(a) > get<0>(b);
    }
    if(get<1>(a) != get<1>(b)){ //max
        return get<1>(a) > get<1>(b);
    }
    return get<2>(a) > get<2>(b);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        v.clear();
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int people;
            scanf("%d",&people);
            
            long long sum=0ll;
            int mymax=-1;
            vector<int> quan(people,0);
            for(int j=0;j<people;j++){
                scanf("%d",&quan[j]);
                mymax = max(mymax,quan[j]);
                sum += quan[j];
            }
            v.emplace_back(sum, mymax, people, quan);
        }
        stable_sort(v.begin(), v.end(), cmp);
        for(int i = 0;i < v.size();i++){
            for(int j = 0;j < get<2>(v[i]);j++){
                printf("%d ", get<3>(v[i])[j]);
            }
            printf("\n");
        }
    }
    return 0;
}