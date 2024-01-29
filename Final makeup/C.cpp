#include<bits/stdc++.h>
using namespace std;
long long a[100010];
struct Item {
    long long max_element, tag;
    int cnt;

    Item(long long max_element = 0, int cnt = 0, long long tag = 0) : max_element(max_element), cnt(cnt), tag(tag) {}

    friend Item operator+(const Item &L, const Item &R) {
        Item res(0, 0);
        if(L.max_element + L.tag > R.max_element + R.tag){
            res.max_element = L.max_element + L.tag;
            res.cnt = L.cnt;
        }else if(L.max_element + L.tag < R.max_element + R.tag){
            res.max_element = R.max_element + R.tag;
            res.cnt = R.cnt;
        }else{
            res.max_element = L.max_element + L.tag;
            res.cnt = L.cnt + R.cnt;
        }
        return res;
    }
};
Item seg[4 * 100010];

void pull(int l, int r, int id) {
    int m = (l + r) / 2;
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

void push(int l, int r, int id) {
    seg[id].max_element += seg[id].tag;
    seg[id * 2].tag += seg[id].tag;
    seg[id * 2 + 1].tag += seg[id].tag;
    seg[id].tag = 0;
}

void build(int l, int r, int id = 1) {
    if (l == r) {
        seg[id] = Item(a[l], 1, 0);
        return;
    }
    int m = (l + r) / 2;
    build(l, m, 2 * id);
    build(m + 1, r, 2 * id + 1);
    pull(l, r, id);
}

Item query(int ql, int qr, int l, int r, int id = 1) {
    if (qr < l || r < ql){ // [l,r] not in [ql,qr]
        return Item(0);
    }
    if (ql <= l && r <= qr){ // [l,r] in [ql,qr]
        return seg[id];
    }
    push(l, r, id);
    int m = (l + r) / 2; // recursion on remaining part
    return query(ql, qr, l, m, id * 2) + query(ql, qr, m + 1, r, id * 2 + 1);
}

void update(int ql, int qr, int val, int l, int r, int id = 1) {
    if (qr < l || r < ql) // not in range
        return;
    if (ql <= l && r <= qr) { // in range => modify tag
        seg[id].tag += val;
        return;
    }
    push(l, r, id); // push before split in half
    int m = (l + r) / 2;
    update(ql, qr, val, l, m, id * 2);
    update(ql, qr, val, m + 1, r, id * 2 + 1);
    pull(l, r, id); // pull after finish
}
void print_tree(int n){
    for(int i=1;i<4*n;i++){
        printf("seg[%d]={%lld,%d,%lld}\n",i,seg[i].max_element, seg[i].cnt, seg[i].tag);
    }
}

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    build(0, n - 1);
    //print_tree(n);
    while(q--){
        int type,l,r;
        scanf("%d%d%d",&type,&l,&r);
        l--,r--;
        if(type==1){
            int v;
            scanf("%d",&v);
            update(l, r, v, 0, n - 1);
        }else{
            auto item=query(l, r, 0, n - 1);
            printf("%lld %d\n", item.max_element + item.tag, item.cnt);
        }
        //print_tree(n);
    }
    return 0;
}