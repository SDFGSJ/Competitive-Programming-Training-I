/*
Problem Name: Forest Queries II
Problem Link: https://cses.fi/problemset/task/1739
Author: Sachin Srivastava (mrsac7)
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename... T>
void see(T&... args) { ((cin >> args), ...);}
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {cerr << *it << "=" << a << ", "; err(++it, args...);}
// #define int long long
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define vi vector<int>
#define vii vector<pii>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

const ll inf = 1LL<<62;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int T[1005][1005],n;
void upd(int x, int y, int a) {
    for (;x <=n; x+= x&-x) {
        for (int j = y;j<=n; j+= j&-j) T[x][j] += a;
    }
}
int qry(int x, int y) {
    int s = 0;
    for (;x>0; x-= x&-x) {
        for (int j = y ;j>0; j-= j&-j ) s+= T[x][j];
    }
    return s;
}
int a[1005][1005];
void solve(){
    int q; see(n,q);
    rep(i,1,n+1) {
        rep(j,1,n+1) {
            char x; see(x);
            a[i][j] = (x=='*');
            if (x=='*') upd(i,j,1);
        }
    }
    while(q--){
        int z; see(z);
        if (z==1) {
            int x,y; see(x,y);
            int k =  (a[x][y]^1) - a[x][y];
            a[x][y]^=1;
            upd(x,y,k);
        }
        else {
            int x1,y1,x2,y2; see(x1,y1,x2,y2);
            int ans = qry(x2,y2) - qry(x1-1,y2) - qry(x2,y1-1) + qry(x1-1,y1-1);
            put(ans);
        }
    }
}
signed main(){
    IOS;
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t=1;
    //cin>>t;
    rep(i,1,t+1){
        solve();
        cout<<'\n';
    }
    #ifdef LOCAL
    clock_t tStart = clock();
    cerr<<fixed<<setprecision(10)<<"\nTime Taken: "<<(double)(clock()- tStart)/CLOCKS_PER_SEC<<endl;
    #endif
}
/*
ref:
https://github.com/mrsac7/CSES-Solutions/blob/master/src/1739%20-%20Forest%20Queries%20II.cpp
*/