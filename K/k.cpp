#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

void runTests() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<bool> dp(k + 1, false);
	//dp[i] == 0 means, Jiro wins with i stones at start
	//dp[i] == 1 .....Taro

	for(int i = 1; i <= k; i++) {
		//try out all the stones & find if for any Jiro wins(dp[j] == 0) on next wins
		bool TaroWins = false; //Jiro wins
		for(int j = 0; j < n; j++) {  //O(1e7)
			if(i - a[j] >= 0) {
				if(dp[i - a[j]] == false) {
					TaroWins = true;
				}
			}
		}
		dp[i] = TaroWins;
	}

	cout << (dp[k] ? "First\n" : "Second\n");
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
