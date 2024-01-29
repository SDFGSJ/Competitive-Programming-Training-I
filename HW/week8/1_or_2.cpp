#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
constexpr int mod = 1e9+7;
constexpr int MAXN = 1e5 + 10;
vvi gph(MAXN, vi{});
bool vis[MAXN];

void dfs(int u)
{
    vis[u] = true;
    for(auto v : gph[u])
        if(!vis[v])dfs(v);
    return;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=0; i<m; ++i)
    {
        int x, y, z; cin >> x >> y >> z;
        gph[x].emplace_back(y);
        gph[y].emplace_back(x);
    }
    int ans = 0;
    for(int i=1; i<n+1; ++i)
    {
        if(!vis[i]){dfs(i); ans++;}
    }
    cout << ans << '\n';
}