#include <iostream>
using namespace std;

int n, m, h[200005], r, st[200005<<2];

void update(int x, int l, int r, int u){
    if (l == r){
        st[x] = h[l];
        return;
    }
    int mid = (l+r)>>1;
    if (u <= mid) update(x<<1, l, mid, u);
    else update(x<<1|1, mid+1, r, u);
    st[x] = max(st[x<<1], st[x<<1|1]);
}
int query(int x, int l, int r, int q){
    if (l == r) return l;
    int mid = (l+r)>>1;
    if (st[x<<1] >= q) return query(x<<1, l, mid, q);
    else return query(x<<1|1, mid+1, r, q);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> h[i];
        update(1, 1, n, i);
    }
    for (int i = 0; i < m; i++){
        cin >> r;
        if (r > st[1]) cout << 0 << " ";
        else{
            int idx = query(1, 1, n, r);
            cout << idx << " ";
            h[idx] -= r;
            update(1, 1, n, idx);
        }
    }
    cout << "\n";
}
/*
ref:
https://yuihuang.com/cses-1143/
*/