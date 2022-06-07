#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n; cin >> n;

	vector<int> a(n);
	vector<int> pre(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		if(i == 0) 
			pre[i] = a[i];
		else 
			pre[i] = a[i] + pre[i - 1];
	}


	vector<vector<int>> dp(n, vector<int>(n, -1));
	//dp[i][j] - minimum cost to combine slimes[i....j]

	for(int len = 1; len <= n; len++) {
		for(int row = 0; row < n; row++) {
			int col = row + len - 1;

			if(col >= n) break;

			if(len == 1) {
				dp[row][col] = 0;
				continue;
			}	

			int to_subtract = (row == 0 ? 0 : pre[row - 1]);
			int subSegSum = pre[col] - to_subtract;		

			//slimes[row...j] & slimes[j + 1...col]
			for(int j = row; j < col; j++) { 
				if(dp[row][col] == -1 || dp[row][col] > dp[row][j] + dp[j + 1][col] + subSegSum) {
					dp[row][col] = dp[row][j] + dp[j + 1][col] + subSegSum;
				}
			}

		}
	}

	cout << dp[0][n - 1] << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
