#include<bits/stdc++.h>
using namespace std;
char str[100010];
int main(){
    int i,j;
    while(~scanf("%s",str)){
        list<char> ans;
        int len=strlen(str);
        for(i=0;i<len;){
            if(str[i]=='['){
                i++;    //move to next char
                int l=i;
                while(i<len && str[i]!='[' && str[i]!=']'){ //find first non '[]' char
                    i++;
                }

                for(j=i-1;j>=l;j--){
                    ans.push_front(str[j]);
                }
            }else if(str[i]==']'){
                i++;
                while(i<len && str[i]!='[' && str[i]!=']'){
                    ans.push_back(str[i]);
                    i++;
                }
            }else{
                ans.push_back(str[i]);
                i++;
            }
        }
        for(auto c:ans){
            printf("%c",c);
        }
        printf("\n");
    }
    return 0;
}