#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n, W; cin >> n >> W;
	vector<vector<int>> wv (n, vector<int>(2));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			cin>> wv[i][j];
		}
	}

	vector<int> dp(W + 1, 0);

	//dp[i][j] - maximum total value if we considered first i items 
	//and knapsack weight is j;
	//since we need only previous row, we can reduce space complexity by only keeping track
	//of prev row & by visiting each row from right to left;

	for(int i = 1; i <= n; i++) {
		//considering i-1 th item
		for(int j = W; j >= 0; j--) {
			if(j - wv[i - 1][0] >= 0) {
				dp[j] = max(dp[j], dp[j - wv[i - 1][0]] + wv[i - 1][1]);
			}
		}
	}

	cout << dp[W] << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
