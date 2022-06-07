#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	string s, t; cin >> s >> t;

	int n = s.size();
	int m = t.size();

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i - 1] == t[j - 1]) {
				dp[i][j] = max({
					dp[i - 1][j - 1] + 1,
					dp[i - 1][j],
					dp[i][j - 1]
				});
			} else {
				dp[i][j] = max({
					dp[i][j - 1],
					dp[i - 1][j]
				});
			}
		}
	}

	string ans = "";

	int i = n, j = m;
	while(i > 0 && j > 0) {
		if(s[i - 1] == t[j - 1]) {
			//include this in ans
			ans += s[i - 1];
			i--;
			j--;
		} else if (dp[i][j] == dp[i - 1][j]) {
			i--;
		} else {
			j--;
		}
	}

	reverse(ans.begin(), ans.end());

	cout << ans << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
