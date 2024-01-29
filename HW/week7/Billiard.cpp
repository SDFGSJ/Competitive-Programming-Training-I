#include <iostream>
using namespace std;

typedef long long int ll;

pair<ll, ll> extgcd(ll a, ll b) {
    if (b == 0) return {1, 0};
    auto [xp, yp] = extgcd(b, a % b);
    return {yp, xp - a / b * yp};
}

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    //freopen("testcase.txt", "r", stdin);
    int t;
    int n, m, x, y, vx, vy, c;
    cin >> t;
    while (t--) {
        cin >> n >> m >> x >> y >> vx >> vy;
        if (vx == 0 && vy == 0) {
            cout << -1 << endl;
            continue;
        }
        if (vy == 0) {
            if (y == 0) {
                if (vx < 0) cout << "0 0" << endl;
                else cout << n << " " << 0 << endl;
            } else if (y == m) {
                if (vx < 0) cout << "0 " << m << endl;
                else cout << n << " " << m << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        if (vx == 0) {
            if (x == 0) {
                if (vy < 0) cout << "0 0" << endl;
                else cout << "0 " << m << endl;
            } else if (x == n) {
                if (vy < 0) cout << n << " " << 0 << endl;
                else cout << n << " " << m << endl;
            } else {
                cout << -1 << endl;
            }
            continue;
        }
        if (vx == -1) {
            x = n - x;
        }
        if (vy == -1) {
            y = m - y;
        }
        int c = x - y;
        //cout <<c;
        //c = (c + n) % n;
        if (c % gcd(m, n)) {
            cout << -1 <<endl;
            continue;
        }
        auto ans = extgcd(n, m);
        int gd = gcd(m, n);
        int times = c / gd;
        ans.first *= times;
        int dx = m / gd;
        ans.first = ans.first % dx + (ans.first <= 0) * dx;
        ans.second = - (c - ans.first*n) / m;
        //cout <<ans.first <<" " <<ans.second << endl;

        //int ix = !(ans.first & 1), iy = !(ans.second & 2);
        int ix = (ans.first & 1) * n;
        int iy = (ans.second & 1) * m;
        if (vx == -1) ix = n - ix;
        if (vy == -1) iy = m - iy;
        cout << ix << " " << iy << endl;
    }
}
