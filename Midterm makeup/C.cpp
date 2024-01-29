#include<bits/stdc++.h>
using namespace std;
int a[100010];
multiset<long> posi,neg,dist;
unordered_map<int,int> m; //<num,cnt>
const int left_wall = -1000000000;  //for simpler implementation
const int right_wall = INT_MAX;
void debug(){
    printf("posi=[");
    for(auto i:posi){
        printf("%d ",i);
    }
    printf("]\nneg=[");
    for(auto i:neg){
        printf("%d ",i);
    }
    printf("]\ndist=[");
    for(auto i:dist){
        printf("%d ",i);
    }
    printf("]\n");
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){   //init posi,neg,m
        scanf("%d",&a[i]);
        posi.emplace(a[i]);
        neg.emplace(-a[i]);
        m[a[i]]++;
    }

    //init dist
    sort(a,a+n);
    for(int i=0;i+1<n;i++){
        dist.emplace(a[i+1]-a[i]);
    }

    //walls
    posi.emplace(left_wall);posi.emplace(right_wall);
    neg.emplace(-left_wall);neg.emplace(-right_wall);
    dist.emplace(a[0]-left_wall);dist.emplace(right_wall-a[n-1]);

    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        //debug();
        int type,p;
        scanf("%d%d",&type,&p);
        if(type==1){    //1 student from position p leaves the line
            posi.erase(posi.find(p));
            neg.erase(neg.find(-p));

            //find left, right neightbors of p
            int l = -(*neg.lower_bound(-p));
            int r = *posi.lower_bound(p);

            if(m[p]>1){ //if there are multiple p's, just erase 1 zero
                dist.erase(dist.find(0));
            }else{
                dist.emplace(r-l);
                dist.erase(dist.find(r-p));
                dist.erase(dist.find(p-l));
            }
            m[p]--;
        }else{  //1 student cut in line at position p
            int l = -(*neg.lower_bound(-p));
            int r = *posi.lower_bound(p);
            posi.emplace(p);
            neg.emplace(-p);

            if(m[p]>=1){    //if there are already 1 p in the queue
                dist.emplace(0);    //just queue after p
            }else{
                dist.erase(dist.find(r-l));
                dist.emplace(r-p);
                dist.emplace(p-l);
            }
            m[p]++;
        }

        //if no one in the queue, the min dist would be -1147483649(overflow but doesnt matter)
        if(posi.size()>2 && *dist.begin()<k){
            printf("QQ\n");
        }else{
            printf("OuOb\n");
        }
    }
    return 0;
}