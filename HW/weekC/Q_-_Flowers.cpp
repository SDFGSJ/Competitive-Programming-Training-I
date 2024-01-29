#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 2e5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2
class segtree{
    public:
    int n;
    vector<ll> tree;
    segtree(int _n){
        n=_n;
        tree.resize(n*4);
    }
    void uthaw(int nd){
        tree[nd]=max(tree[lft],tree[rgt]);
    }
    void update(int nd, int b, int e, int l, int r, ll x){
        if(b>e or e<l or r<b)return;
        if(l<=b and e<=r){
            tree[nd]+=x;
            return;
        }
        update(lft,b,mid,l,r,x);
        update(rgt,mid+1,e,l,r,x);
        uthaw(nd);
    }
    ll query(int nd, int b, int e, int l, int r){
        if(b>e or e<l or r<b)return 0;
        if(l<=b and e<=r){
            return tree[nd];
        }
        ll p1 = query(lft,b,mid,l,r);
        ll p2 = query(rgt,mid+1,e,l,r);
        return max(p1,p2);
    }
};
int main(){
    FIO;
    // file();
    int n; cin>>n;
    segtree obj(N);
    vi a(n),b(n);
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];
    for(int i=0; i<n; i++){
        ll mx = obj.query(1,1,N,1,a[i]-1);
        obj.update(1,1,N,a[i],a[i],mx+b[i]);
    }
    cout<<obj.query(1,1,N,1,N)<<endl;
}