#include<bits/stdc++.h>
using namespace std;
tuple<int, int, string> v[10010];    //<position, age, name>
bool cmp(const tuple<int, int, string>& a, const tuple<int, int, string>& b){
    if(get<0>(a) != get<0>(b)){ //position
        return get<0>(a) < get<0>(b);
    }else{
        if(get<0>(a)==5){   //appentice
            if(get<1>(a) != get<1>(b)){
                return get<1>(a) < get<1>(b);   //younger first
            }else{  //same age
                return get<2>(a) < get<2>(b);
            }
        }else{
            if(get<1>(a) != get<1>(b)){
                return get<1>(a) > get<1>(b);   //older first
            }else{  //same age
                return get<2>(a) < get<2>(b);
            }
        }
    }
}
// since the vector will grow automatically and filled with 0s
// so if we use 1~8, 0s will be in the front, which is undesired
// so use -8~-1
// array is ok with 1~8
int convert(string position){  //map position to int
    if(position=="elder"){
        return 1;
    }else if(position=="nursy"){
        return 2;
    }else if(position=="kit"){
        return 3;
    }else if(position=="warrior"){
        return 4;
    }else if(position=="appentice"){
        return 5;
    }else if(position=="medicent"){
        return 6;
    }else if(position=="deputy"){
        return 7;
    }else if(position=="leader"){
        return 8;
    }else{
        return 0;
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            string name,posi;
            int age;
            cin>>name>>posi>>age;
            v[i]=make_tuple(convert(posi),age,name);
        }
        sort(v,v+n,cmp);
        for(int i=0;i<min(n,m);i++){
            cout<<get<2>(v[i])<<'\n';
        }
    }
    return 0;
}