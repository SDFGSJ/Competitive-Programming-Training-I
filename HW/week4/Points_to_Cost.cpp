#include<bits/stdc++.h>
using namespace std;
int n,c,minx=INT_MAX,maxx=-1;
vector<pair<int,int>> v;    //<x,y>
double f(double p){
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=(pow(p - v[i].first, 2) + pow(c - v[i].second, 2));
    }
    return sum;
}
template <typename FuncTy>
pair<double, double> ternarySearch(double L, double R, FuncTy func, double eps = 1e-6) {
    while (L + eps < R) {
        double mL = L + (R - L) / 3;
        double mR = R - (R - L) / 3;
        if (func(mL) > func(mR))
            L = mL;
        else
            R = mR;
    }
    return {L, R};
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v.emplace_back(x,y);
        minx=min(minx,x);   //min x will be left bound
        maxx=max(maxx,x);   //max x will be right bound
    }
    auto [l,r] = ternarySearch(minx,maxx,f);
    printf("%f\n",f(l));    //print cost
    return 0;
}
