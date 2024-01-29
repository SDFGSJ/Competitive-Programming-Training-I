#include<bits/stdc++.h>
using namespace std;
char s[3010],t[3010];
int dp[3010][3010];
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs(int m, int n){
	/* Following steps build L[m+1][n+1] in bottom up
	fashion. Note that L[i][j] contains length of LCS of
	X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

    vector<char> str;

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0) {
		// If current character in s and t are same, then
		// current character is part of LCS
		if (s[i - 1] == t[j - 1]) {
            str.emplace_back(s[i-1]);
			i--;
			j--;
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (dp[i - 1][j] > dp[i][j - 1])
			i--;
		else
			j--;
	}

    reverse(str.begin(),str.end());
	for(auto c:str){
        cout<<c;
    }
	cout<<'\n';
}
int main(){
    scanf("%s%s",s,t);
	int m = strlen(s);
	int n = strlen(t);
	lcs(m, n);
	return 0;
}
/*
ref:
https://www.geeksforgeeks.org/printing-longest-common-subsequence/
*/