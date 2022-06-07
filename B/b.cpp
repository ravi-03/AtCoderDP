#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n, k; cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}

	vector<int> dp(n, -1); //dp[i] - min cost to reach i-th stone
	dp[0] = 0;

	for(int i = 1; i < n; i++) {
		for(int j = max(0LL, i - k); j < i; j++) {
			if(dp[i] == -1 || dp[i] > dp[j] + abs(h[i] - h[j])) {
				dp[i] = dp[j] + abs(h[i] - h[j]);
			}
		}
	}

	cout << dp[n - 1] << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
