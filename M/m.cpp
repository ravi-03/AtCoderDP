#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int mod = 1e9 + 7;

void runTests() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<vector<int>> dp(n, vector<int>(k + 1));
	//dp[i][j] - What is the number of ways if i have first (i + 1) children & i have j candies for distribution
	//and then propagate the result along the row for O(1) access for each cell in next row;

	//if i have zero candies number of ways is 1 always
	for(int row = 0; row < n; row++) {
		dp[row][0] = 1;
	}

	//if i have only one child there is only one way for j <= a[0]
	for(int col = 1; col <= k; col++) {
		if(a[0] >= col) //as no candies can be left, capacity must be greater than candies
			dp[0][col] = 1 + dp[0][col - 1];
		else
			dp[0][col] = dp[0][col - 1];
	}

	int totalCapacityTillNow = a[0];

	for(int row = 1; row < n; row++) {
		totalCapacityTillNow += a[row];
		for(int col = 1; col <= k; col++) {

			if(totalCapacityTillNow < col) {
				dp[row][col] = dp[row][col - 1];
				continue;
			} 

			int to_subtract = 0;
			int leftBound = col - a[row]; //giving max possible to row-th child
			if(leftBound - 1 >= 0) {
				to_subtract = dp[row - 1][leftBound - 1];
			}
			dp[row][col] = ((dp[row - 1][col] - to_subtract + mod) % mod + dp[row][col - 1]) % mod;
		}
	}

	cout << (k - 1 >= 0 ? (dp[n - 1][k] - dp[n - 1][k - 1] + mod) % mod : dp[n - 1][k]) << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
