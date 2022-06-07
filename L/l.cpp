#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n, vector<int>(n)); //dp[i][j] will give max X-Y & min X-Y if Taro starts
												//with initial sequence [i : j]

	for(int len = 1; len <= n; len++) {
		for(int row = 0; row < n; row++) {
			int col = row + len - 1;
			if(col >= n) break;
			if(row == col) {
				dp[row][col] = a[row];
			} else {
				dp[row][col] = max(a[col] - dp[row][col - 1], a[row] - dp[row + 1][col]); //(Taro picks from last, first respectively)
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
