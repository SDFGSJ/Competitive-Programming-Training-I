#include <iostream>
using namespace std;

int n, dp[505][63000], mod = 1e9+7;

int main() {
    cin >> n;
    int tar = n * (n+1) / 2;
    if (tar % 2) {
        cout << 0;
        return 0;
    }
    tar /= 2;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= tar; j++){
            dp[i][j] += dp[i-1][j];
            dp[i][j] %= mod;
            if (j >= i){
                dp[i][j] += dp[i-1][j-i];
                dp[i][j] %= mod;
            }
        }
    }
    long long ans = dp[n][tar];
    ans *= 500000004;
    ans %= mod;
    cout << ans << "\n";
}
/*
ref:
https://yuihuang.com/cses-1093/
*/