#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    stack<char> s;
    int len=str.length();
    for(int i=0;i<len;i++){
        if(str[i]=='T' && s.size() && s.top()=='S'){    //cleaner code
            s.pop();
        }else{
            s.push(str[i]);
        }
    }
    cout<<s.size()<<'\n';
    return 0;
}