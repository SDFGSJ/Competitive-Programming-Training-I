#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main(){
    int n,i,j;
    cin>>n;
 
    v.push_back("0");
    v.push_back("1");   // [0,1]
    for(i=2;i<(1<<n);i<<=1){
        for(j=i-1;j>=0;j--){    // reverse v and append to the end of v
            v.push_back(v[j]);  // [0,1,1,0]
        }
        for(j=0;j<i;j++){   // for the first half of the elements in v, append 0 to the front
            v[j]="0"+v[j];  // [00,01,1,0]
        }
        for(j=i;j<2*i;j++){ // for the second half of the elements in v, append 1 to the front
            v[j]="1"+v[j];  // [00,01,11,10]
        }
    }
    for(auto i:v){
        cout<<i<<'\n';
    }
    return 0;
}