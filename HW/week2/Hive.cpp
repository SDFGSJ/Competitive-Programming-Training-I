#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tll tuple<ll,ll,ll>
#define mp make_pair

using namespace std;

const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

int N, M;
int sx[3], sy[3], tx[3], ty[3];
int g[11][6];
int res = INF;
int c[11][6][6];



bool ok(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(int x, int y, int cur) {
    if (x == N) {
        res = min(res, cur);
        //cout << res << "????" << endl;
        return;
    }
    if (cur >= res) return;
    for (int i = 0; i < 6; i++) c[x][y][i] = 0;

    vector<int> nxt(6, 1);

    if (y == M - 1) nxt[3] = 0;
    if (x == N - 1 || x % 2 == 0 && y == 0) nxt[4] = 0;
    if (x == N - 1 || x % 2 == 1 && y == M - 1) nxt[5] = 0;
    int a = 0, b = 0;


    int nx = x - 1, ny = (x % 2 == 0 ? y - 1 : y);
    if (ok(nx, ny)) c[x][y][0] = c[nx][ny][5], a += c[x][y][0] == 1, b += c[x][y][0] == 2;
    nx = x - 1, ny = (x % 2 == 0 ? y : y + 1);
    if (ok(nx, ny)) c[x][y][1] = c[nx][ny][4], a += c[x][y][1] == 1, b += c[x][y][1] == 2;
    nx = x, ny = y - 1;
    if (ok(nx, ny)) c[x][y][2] = c[nx][ny][3], a += c[x][y][2] == 1, b += c[x][y][2] == 2;

    nx = (y < M - 1 ? x : x + 1);
    ny = (y < M - 1 ? y + 1 : 0);



    if (x == sx[1] && y == sy[1] || x == tx[1] && y == ty[1]) {
        if (b > 0 || a >= 2) return;
        else if (a == 1) dfs(nx, ny, cur + g[x][y]);
        else {
            for (int i = 3; i <= 5; i++) {
                if (nxt[i]) {
                    c[x][y][i] = 1;
                    dfs(nx, ny, cur + g[x][y]);
                    c[x][y][i] = 0;
                }
            }
        }
    }
    else if (x == sx[2] && y == sy[2] || x == tx[2] && y == ty[2]) {
        if (a > 0 || b >= 2) return;
        else if (b == 1) dfs(nx, ny, cur + g[x][y]);
        else {
            for (int i = 3; i <= 5; i++) {
                if (nxt[i]) {
                    c[x][y][i] = 2;
                    dfs(nx, ny, cur + g[x][y]);
                    c[x][y][i] = 0;
                }
            }
        }
    }
    else {
        if (a > 0 && b > 0 || a > 2 || b > 2) return;
        if (a == 0 && b == 0) {
            dfs(nx, ny, cur);
            for (int j = 1; j <= 2; j++) {
                for (int skip = 3; skip <= 5; skip++) {
                    bool tmp = 1;
                    for (int i = 3; i <= 5; i++) {
                        if (i == skip) c[x][y][i] = 0;
                        else {
                            if (!nxt[i]) {
                                tmp = 0;
                                break;
                            }
                            c[x][y][i] = j;
                        }
                    }
                    if (tmp) dfs(nx, ny, cur + g[x][y]);
                }
            }
        }
        else if (a == 1 || b == 1) {
            for (int i = 3; i <= 5; i++) {
                if (nxt[i]) {
                    c[x][y][i] = (a ? 1 : 2);
                    dfs(nx, ny, cur + g[x][y]);
                    c[x][y][i] = 0;
                }
            }
        }
        else if (a == 2 || b == 2) {
            dfs(nx, ny, cur + g[x][y]);
        }
    }
    return;
}


void solve() {
    cin >> N >> M;
    cin >> sx[1] >> sy[1] >> tx[1] >> ty[1] >> sx[2] >> sy[2] >> tx[2] >> ty[2];
    for (int i = 1; i <= 2; i++) {
        sx[i]--;
        sy[i]--;
        tx[i]--;
        ty[i]--;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> g[i][j];
        }
    }

    vector<int> cmp;
    for (int j = 0; j < M; j++) {
        for (int k = 1; k <= 2; k++) {
            if (mp(sx[k], sy[k]) == mp(0, j) || mp(tx[k], ty[k]) == mp(0, j)) cmp.push_back(k);
        }
    }
    for (int j = 1; j < N; j++) {
        for (int k = 1; k <= 2; k++) {
            if (mp(sx[k], sy[k]) == mp(j, M - 1) || mp(tx[k], ty[k]) == mp(j, M - 1)) cmp.push_back(k);
        }
    }
    for (int j = M - 2; j >= 0; j--) {
        for (int k = 1; k <= 2; k++) {
            if (mp(sx[k], sy[k]) == mp(N - 1, j) || mp(tx[k], ty[k]) == mp(N - 1, j)) cmp.push_back(k);
        }
    }
    for (int j = N - 2; j >= 1; j--) {
        for (int k = 1; k <= 2; k++) {
            if (mp(sx[k], sy[k]) == mp(j, 0) || mp(tx[k], ty[k]) == mp(j, 0)) cmp.push_back(k);
        }
    }
    if (cmp == vector<int>({1, 2, 1, 2}) || cmp == vector<int>({2, 1, 2, 1})) {
        cout << -1 << '\n';
        return;
    }

    res = INF;
    memset(c, 0, sizeof(c));
    dfs(0, 0, 0);
    if (res == INF) cout << -1 << '\n';
    else cout << res << '\n';
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll TestCases = 1;
    cin >> TestCases;

    while (TestCases--) {
        solve();
    }
}