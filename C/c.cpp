#include<bits/stdc++.h>
using namespace std;

#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n; cin >> n;
	vector<vector<int>> happ(n, vector<int>(3));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> happ[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(3));
	//dp[i][j] - maximum total happiness till i-th day, if Taro ends up with doing
	//j-th task on i-th day

	dp[0] = happ[0];

	for(int day = 1; day < n; day++) {
		for(int task = 0; task < 3; task++) {
			int prev_max = -1;
			for(int ptask = 0; ptask < 3; ptask++) {
				if(task == ptask) continue;
				if(prev_max == -1 || dp[day - 1][ptask] > prev_max) {
					prev_max = dp[day - 1][ptask];
				}
			}
			dp[day][task] = prev_max + happ[day][task];
		}
	}

	cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
