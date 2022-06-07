#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int inf = 1e18;

void runTests() {

	int n, W; cin >> n >> W;

	vector<vector<int>> wv(n, vector<int>(2));

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 2; j++) {
			cin >> wv[i][j];
		}
	}

	int maxVal = n * 1000;

	vector<vector<int>> dp(n + 1, vector<int>(maxVal + 1, inf));
	//dp[i][j] - minimum weight we need to have to get a value exactly j & by considering
	//only first i items

	//make first column zero, as we want at max 0 values
	for(int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= maxVal; j++) {
			// //not taking this item
			dp[i][j] = dp[i - 1][j];
			if(j - wv[i - 1][1] >= 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - wv[i - 1][1]] + wv[i - 1][0]);
			}
		}
	}

	int final_ans = 0;

	//search in last row from right first weight which is less or equal to given W
	for(int i = maxVal; i > 0; i--) {
		if(dp[n][i] <= W) {
			final_ans = i;
			break;
		}
	}

	cout << final_ans << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
