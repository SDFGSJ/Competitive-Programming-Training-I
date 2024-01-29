#include<bits/stdc++.h>
using namespace std;
int len;
bool visited[10];   // visited[i]=true if s[i] is in str[]
string s,str;
set<string> myset;  // prevent duplicate permutation
void dfs(int i){
    if(i==len){
        myset.insert(str);
        return;
    }

    for(int j=0;j<len;j++){
        if(visited[j]){
            continue;
        }
        visited[j]=true;
        str.push_back(s[j]);
        dfs(i+1);
        str.pop_back();
        visited[j]=false;
    }
}
int main(){
    cin>>s;
    len=s.length();
    sort(s.begin(),s.end());
    dfs(0);
    cout<<myset.size()<<'\n';
    for(auto& s:myset){
        cout<<s<<'\n';
    }
    return 0;
}