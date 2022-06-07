#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

int n; 
vector<double> p;

void runTests() {
	cin >> n;
	p.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	double dp[n + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	//dp[i][j] = probability of getting j heads with first (i + 1) coins

	//base case
	dp[0][0] = 1;

	double val = 1;

	for(int coins = 1; coins <= n; coins++) {
		val *= (1 - p[coins - 1]);
		dp[coins][0] = val;
	}

	//dp[coins][heads]

	for(int coins = 1; coins <= n; coins++) {
		for(int heads = 1; heads <= coins; heads++) {
			//this coins gives heads
			dp[coins][heads] = p[coins - 1] * dp[coins - 1][heads - 1];
			//this coins gives tails
			dp[coins][heads] += (1 - p[coins - 1]) * dp[coins - 1][heads];
		}
	}

	double final_ans = 0;

	for(int heads = n / 2 + 1; heads <= n; heads++) {
		final_ans += dp[n][heads];
	}

	cout << fixed << setprecision(10) << final_ans << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
