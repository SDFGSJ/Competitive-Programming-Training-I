#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
constexpr int mod = 1e9+7;
constexpr int MAXN = 1e5 + 10;

class DisjointSet
{
public:
    vector<int> parent;
    int find_root(int x){
        if(x == parent[x]) return x;
        int root = find_root(parent[x]);
        return parent[x] = root;
    }
    DisjointSet(size_t n) : parent(n+1) { init(); }
    void init(){
        for(size_t i=0; i < parent.size(); ++i)
            parent[i] = i;
    }
    bool Same(int a, int b) { return find_root(a) == find_root(b); }
    void Union(int a, int b) { parent[find_root(a)] = find_root(b); }
};
void read_gph(DisjointSet& G, int n)
{
    for(int i=0, u, v; i<n; ++i)
    {
        cin >> u >> v;
        G.Union(u, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, k, l; cin >> n >> k >> l;
    DisjointSet G1(n), G2(n);
    map<pair<int, int>, int> map;
    read_gph(G1, k);
    read_gph(G2, l);
    for(int i=1; i<=n; ++i){
        map[{G1.find_root(i), G2.find_root(i)}]++;
    }
    for(int i=1; i<=n; ++i){
        cout << map[{G1.find_root(i), G2.find_root(i)}] << " ";
    }
}