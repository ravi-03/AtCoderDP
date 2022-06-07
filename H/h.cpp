#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

const int mod = 1e9 + 7;

void runTests() {
	int h, w; cin >> h >> w;
	vector<vector<char>> a(h, vector<char>(w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}

	vector<vector<int>> dp(h, vector<int>(w));

	for(int i = 0; i < h; i++) {
		if(a[i][0] == '#') break;
		dp[i][0] = 1;
	}
	for(int i = 0; i < w; i++) {
		if(a[0][i] == '#') break;
		dp[0][i] = 1;
	}

	for(int i = 1; i < h; i++) {
		for(int j = 1; j < w; j++) {
			if(a[i][j] == '#') continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}

	cout << dp[h - 1][w - 1] << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
