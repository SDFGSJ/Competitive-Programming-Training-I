#include<bits/stdc++.h>
using namespace std;

int n, a, b, dis[200005];
vector<int> v[200005];

vector<int> bfs(int x){
    vector<int> ret(n+1, -1);
    queue<int> q;
    q.push(x);
    ret[x] = 0;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (auto i:v[now]){
            if (ret[i] != -1) continue;
            q.push(i);
            ret[i] = ret[now]+1;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> ret = bfs(1);
    int idx = 0;
    for (int i = 1; i <= n; i++){
        if (ret[i] > ret[idx]) idx = i;
    }
    vector<int> ans = bfs(idx);
    idx = 0;
    for (int i = 1; i <= n; i++){
        if (ans[i] > ans[idx]) idx = i;
    }
    ret = bfs(idx);
    for (int i = 1; i <= n; i++){
        cout << max(ans[i], ret[i]) << " ";
    }
    cout << "\n";
}
/*
ref:
https://yuihuang.com/cses-1132/
*/