#include<bits/stdc++.h>
#define ll long long
#define maxn 2010
#define mod 998244353
using namespace std;
struct cv {
	int mp[6][6];
	int mov;
	friend bool operator<(cv p, cv q) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (p.mp[i][j] != q.mp[i][j]) return p.mp[i][j] < q.mp[i][j];
			}
		}
		return p.mp[0][0] < q.mp[0][0];
	}
}dd, hf;
int to[4][2] = { 0,1,0,-1,1,0,-1,0 };
int main() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			scanf("%d", &dd.mp[i][j]);
		}
	}
	dd.mov = 0;
	queue<cv>q;
	q.push(dd);
	set<cv>st;
	st.insert(dd);
	while (!q.empty()) {
		dd = q.front();
		q.pop();
		if (dd.mp[2][5] == 1) {
			int cnt = 1;
			for (int i = 4; i >= 0; i--) {
				if (dd.mp[2][i] != 1) break;
				cnt++;
			}
			int ans = (dd.mov + cnt);
			if (ans > 10) ans = -1;
			printf("%d\n", ans);
			return 0;
		}
		if (dd.mov == 10) break;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (dd.mp[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int x = i + to[k][0], y = j + to[k][1];
						if (x < 0 || x >= 6 || y < 0 || y >= 6 || dd.mp[x][y] == 0) {
							continue;
						}
						int xx = x + to[k][0], yy = y + to[k][1];
						if (xx < 0 || xx >= 6 || yy < 0 || yy >= 6 || dd.mp[x][y] != dd.mp[xx][yy]) {
							continue;
						}
						while (xx >= 0 && xx < 6 && yy >= 0 && yy < 6 && dd.mp[x][y] == dd.mp[xx][yy]) {
							xx = xx + to[k][0], yy = yy + to[k][1];
						}
						xx = xx - to[k][0], yy = yy - to[k][1];
						hf = dd;
						hf.mov++;
						swap(hf.mp[i][j], hf.mp[xx][yy]);
						if (!st.count(hf)) {
							st.insert(hf);
							q.push(hf);
						}
					}
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}
/*
refs:
https://www.cnblogs.com/st1vdy/p/12701920.html#a-rush-hour-puzzle
https://blog.csdn.net/qq_45530271/article/details/105258490
https://blog.csdn.net/liufengwei1/article/details/108504327
https://blog.csdn.net/hcl0010101/article/details/120814867
*/