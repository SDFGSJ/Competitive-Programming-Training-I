#include <iostream>
#include <cstring>
using namespace std;

int n, a[5005];
long long dp[5005][5005], pre[5005];

long long f(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];
    if (r-l <= 1) return dp[l][r] = max(a[l], a[r]);
    dp[l][r] = a[l] + pre[r] - pre[l] - f(l+1, r);
    dp[l][r] = max(dp[l][r], pre[r-1] - pre[l-1] - f(l, r-1) + a[r]);
    return dp[l][r];
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i-1]+a[i];
    }
    cout << f(1, n);
}
/*
ref:
https://yuihuang.com/cses-1097/
*/