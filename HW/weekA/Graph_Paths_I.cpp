#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int maxn = 1000005;
int n;
struct mat {
    ll a[100][100];
    mat() {
        memset(a, 0, sizeof(a));
    }
    mat operator * ( const mat &b ) const {
        mat ret;
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                for( int k = 0; k < n; ++k )
                    ret.a[i][j] = ( ret.a[i][j] + a[i][k] * b.a[k][j] ) % mod;
        return ret;
    }
};
void solve() {
    int m, k;
    cin >> n >> m >> k;
    mat now;
    f(m) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        now.a[x][y]++;
    }
    mat ans;
    f(n) {
        ans.a[i][i] = 1;
    }
    while (k) {
        if (k & 1) {
            ans = ans * now;
        }
        now = now * now;
        k >>= 1;
    }
    cout << ans.a[0][n - 1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        solve();
    }
}
/*
ref:
https://github.com/HanaYukii/CSES/blob/master/1723.cpp
*/