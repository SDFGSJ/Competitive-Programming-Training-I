#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const long long M=1e9+7;
long long fact[N];
long long pow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % M;
        }
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
int main(){
    fact[0]=1;
	for(int i=1;i<N;i++){
		fact[i]=(i*fact[i-1])%M;
	}
    int n;
	scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%lld\n", fact[a] * pow(fact[b], M-2) % M * pow(fact[a-b], M-2) % M);    //fermat little Thm
    }
}
/*
a^(p-1) = 1 mod p <=> a * a^(p-2) = 1 mod p
a^(p-2) is the multi inv of a
*/