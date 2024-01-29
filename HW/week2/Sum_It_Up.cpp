#include<bits/stdc++.h>
using namespace std;
int a[15];
int main(){
    while(1){
        int t,n,sum=0;
        bool hasans=false;
        set<vector<int>, std::greater<vector<int>>> s;
        vector<int> v;

        scanf("%d%d",&t,&n);
        if(n==0){
            break;
        }
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }

        printf("Sums of %d:\n",t);
        for(int i=0;i<(1<<n);i++){  // enumerate
            sum=0;
            v.clear();
            for(int j=0;j<n;j++){   // check every bits
                if(i & (1<<j)){
                    sum+=a[j];
                    v.push_back(a[j]);
                }
            }
            
            if(sum==t && s.count(v)==0){
                hasans=true;
                s.insert(v);
            }
        }

        if(!hasans){
            printf("NONE\n");
        }else{
            for(auto &v:s){
                for(int j=0;j<v.size();j++){
                    if(j==0){
                        printf("%d",v[j]);
                    }else{
                        printf("+%d",v[j]);
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}