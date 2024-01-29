#include<bits/stdc++.h>
using namespace std;
long long a[200010];
struct Node {
    long long data, tag;
};
Node seg[4 * 200010];

long long get_val(int l, int r, int id) {
    return (r - l + 1) * seg[id].tag + seg[id].data;
}
void pull(int l, int r, int id) {
    int m = (l + r) / 2;
    seg[id].data = get_val(l, m, id * 2) + get_val(m + 1, r, id * 2 + 1);
}
void build(int l, int r, int id = 1){
    if (l == r) {
        seg[id].data = a[l];
        seg[id].tag = 0;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * id);
    build(m + 1, r, 2 * id + 1);
    pull(l, r, id);
}
void push(int l, int r, int id) {
    seg[id].data = get_val(l, r, id);
    seg[id * 2].tag += seg[id].tag;
    seg[id * 2 + 1].tag += seg[id].tag;
    seg[id].tag = 0;
}
long long query(int ql, int qr, int l, int r, int id = 1) {
    if (qr < l || r < ql)
        return 0;
    if (ql <= l && r <= qr)
        return get_val(l, r, id); // 注意計算方式
    push(l, r, id); // 多了 push ，注意其被呼叫的位置
    int m = (l + r) / 2;
    return query(ql, qr, l, m, id * 2) + query(ql, qr, m + 1, r, id * 2 + 1);
}
void update(int ql, int qr, int val, int l, int r, int id = 1) {
    if (qr < l || r < ql) // 完全不在範圍內，不做事
        return;
    if (ql <= l && r <= qr) { // 完全位於範圍內，直接改 tag
        seg[id].tag += val;
        return;
    }
    push(l, r, id); // 切兩半前 push
    int m = (l + r) / 2;
    update(ql, qr, val, l, m, id * 2);
    update(ql, qr, val, m + 1, r, id * 2 + 1);
    pull(l, r, id); // 結束後 pull
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    build(0, n - 1);
    for(int i=0;i<q;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int a,b,u;
            scanf("%d%d%d",&a,&b,&u);
            a--,b--;
            update(a, b, u, 0, n - 1);
        }else{
            int k;
            scanf("%d",&k);
            k--;
            long long result=query(k, k, 0, n - 1);
            printf("%lld\n",result);
        }
    }
    return 0;
}