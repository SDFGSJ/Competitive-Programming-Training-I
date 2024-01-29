#include<bits/stdc++.h>
using namespace std;
long long a[200010];
struct Item {
    long long sum, MCS;
    long long prefix_max, postfix_max;
    Item(long long sum = 0) : sum(sum), MCS(max(sum, 0ll)), prefix_max(MCS), postfix_max(MCS) {}
    friend Item operator+(const Item &L, const Item &R) {
        Item res(L.sum + R.sum);
        res.MCS = max({L.MCS, R.MCS, L.postfix_max + R.prefix_max});
        res.prefix_max = max(L.prefix_max, L.sum + R.prefix_max);
        res.postfix_max = max(R.postfix_max, R.sum + L.postfix_max);
        return res;
    }
};
Item seg[4 * 200010];
void pull(int id) {
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
void build(int l, int r, int id = 1) {
    if (l == r) {
        seg[id] = Item(a[l]);
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * id);
    build(m + 1, r, 2 * id + 1);
    pull(id);
}
Item query(int ql, int qr, int l, int r, int id = 1) {
    if (qr < l || r < ql) // [l,r] ���b [ql,qr] ���d��
        return Item(0);
    if (ql <= l && r <= qr) // [l,r] �Q [ql,qr] �����]�t
        return seg[id];
    int m = (l + r) / 2; // �ѤU�N���j�B�z
    return query(ql, qr, l, m, id * 2) + query(ql, qr, m + 1, r, id * 2 + 1);
}
void update(int p, int val, int l, int r, int id = 1) {
    if (p < l || r < p) // �d��~
        return;
    if (l == r) { // �d��
        seg[id] = val;
        return;
    }
    // ����b
    int m = (l + r) / 2;
    update(p, val, l, m, id * 2);
    update(p, val, m + 1, r, id * 2 + 1);
    pull(id); // ���n�ѤF�L�A�ݷ|�O���I���@
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    build(0, n - 1);
    for(int i=0;i<m;i++){
        int k,x;
        scanf("%d%d",&k,&x);
        k--;
        update(k, x, 0, n - 1);
        long long ans=max(0ll, query(0, n-1, 0, n - 1).MCS);
        printf("%lld\n",ans);
    }
    return 0;
}