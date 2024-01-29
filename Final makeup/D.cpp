#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
vector<int> LPFs;
int prime_factor(int x) {   //prime factor decomposition and cal ans
    int ans=1;
    while (x != 1) {
        int factor = LPFs[x], cnt = 0;
        for (;x % factor == 0;++cnt){
            x /= factor;
        }
        if(cnt!=0){ //(cnt+1)^3 - cnt^3 by observation
            ans *= ((cnt+1)*(cnt+1)*(cnt+1) - cnt*cnt*cnt);
        }
    }
    return ans;
}
int main(){
    int t;
    scanf("%d",&t);
    LPFs.assign(2000000+1, 1);
    for (int i = 2; i <= 2000000; ++i) {
        if (LPFs[i] == 1) {
            LPFs[i] = i;
            primes.emplace_back(i);
        }
        for (auto p : primes) {
            if (1LL * i * p > 2000000) break;
            LPFs[i * p] = p;
            if (i % p == 0) break;
        }
    }
    while(t--){
        int k;
        scanf("%d",&k);
        printf("%d\n",prime_factor(k));
    }
    return 0;
}