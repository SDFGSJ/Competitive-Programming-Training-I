#include<bits/stdc++.h>
using namespace std;
int m[200010];
int seg[4*200010];
void buildtree(int id, int l, int r){
    if(l==r){ //leaf
        seg[id] = m[l];
        return;
    }
    int mid = (l+r)/2;
    buildtree(id*2, l, mid);    //left subtree
    buildtree(id*2 + 1, mid+1, r);  //right subtree
    seg[id] = min(seg[id*2], seg[id*2 + 1]);    //min of left,right subtree
}
int query(int id, int l, int r, int ql, int qr){
    if(r<ql || qr<l){   //[l,r] and [ql,qr] has no intersection
        return 1e9;
    }
    if(ql<=l && r<=qr){ //[l,r] is the subinterval of [ql,qr]
        return seg[id];
    }
    int mid = (l+r)/2;

    //min of left, right subtree
    return min(query(id*2, l, mid, ql, qr), query(id*2 + 1, mid+1, r, ql, qr));
}
void modify(int id, int l, int r, int i, int x) {
    if(l==r){   //leaf
        seg[id] = x;
        return;
    }
    int mid = (l+r)/2;


    if(i <= mid){   //at left subtree
        modify(id*2, l, mid, i, x);
    }else{  //at right subtree
        modify(id*2 + 1, mid+1, r, i, x);
    }

    //update the value after modify
    seg[id] = min(seg[id*2], seg[id*2 + 1]);
}
int main(){
    int n,q,i;
    scanf("%d%d",&n,&q);

    //if want to build segment tree, the index must start from 1
    for(i=1;i<=n;i++){
        scanf("%d",&m[i]);
    }

    buildtree(1,1,n);   //build a tree start from id=1, range=[1,n]

    for(i=0;i<q;i++){
        int type,a,b;
        scanf("%d%d%d",&type,&a,&b);
        if(type==1){    //update the value at position a to b
            modify(1,1,n,a,b);
        }else{  //min of range [a,b]
            int ans = query(1,1,n,a,b);
            printf("%d\n",ans);
        }
    }
    return 0;
}