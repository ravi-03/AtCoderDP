#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n; cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<int> dp(n); 
	//dp[i] -> minimum cost to reach i-th stone;
	dp[0] = 0, dp[1] = abs(h[1] - h[0]);

	for(int i = 1; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2] + abs(h[i - 2] - h[i]));
	}
	cout << dp[n - 1] << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
