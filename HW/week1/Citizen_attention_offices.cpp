#include<bits/stdc++.h>
using namespace std;
/*
office[i]: placeid i has an office, 0<office[i]<25
ans[i]: final ans for office location, 0<ans[i]<25
*/
int n,a[30][3],office[10],ans[10],myans=INT_MAX;
void print(){
    for(int i=0;i<5;i++){
        if(i==0){
            printf("%d",ans[i]);
        }else{
            printf(" %d",ans[i]);
        }
    }
    printf("\n");
}
int calc(){
    int sum=0;
    for(int i=0;i<n;i++){   // loop through blocks with people
        int tmp=INT_MAX;
        for(int j=0;j<5;j++){   // loop through all offices
            int placeid=office[j];
            int dx=abs(placeid/5 - a[i][0]);
            int dy=abs(placeid%5 - a[i][1]);
            tmp = min(tmp, (dx+dy)*a[i][2]);    // for every area, only choose the office with min dist, ignore other offices
        }
        sum+=tmp;
    }
    return sum;
}
void dfs(int lv, int cnt){
    if(cnt==5){ // already 5 offices
        int result=calc();
        if(result < myans){
            myans=result;
            for(int k=0;k<5;k++){
                ans[k]=office[k];
            }
        }
        return;
    }

    for(int j=lv;j<25;j++){
        office[cnt]=j;
        dfs(j+1,cnt+1); // the idx of deeper level starts from j+1, not lv+1
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        }
        myans=INT_MAX;
        dfs(0,0);
        print();
    }
    return 0;
}
/* refs:
https://gsourcecode.wordpress.com/2012/02/01/uva-10660/
https://blog.csdn.net/mobius_strip/article/details/86564658
https://theriseofdavid.github.io/2020/03/28/UVa/UVa10660/
*/