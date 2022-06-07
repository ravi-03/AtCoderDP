/*

	https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define debug(x) cout << #x << " : " << x << '\n';

template <class T> void debug_vector(vector<T> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}

const int mod = 1e9 + 7;

void runTests() {
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	int maxn = (1 << n);
	vector<int> dp(maxn); 
	//dp[i] - number of ways to make pairs with first (i + 1) men & any women in subset of size (i + 1);

	dp[0] = 1; //if 0 men & 0 women

	for(int mask = 0; mask < maxn - 1; mask++) {
		int menIndex = __builtin_popcount(mask); //number of men & women finding ans for

		for(int j = 0; j < n; j++) {
			if((mask & (1 << j)) == 0 && a[menIndex][j]) {

				//try to pair menIndex-th men to this j-th women
				dp[mask | (1 << j)] += dp[mask];
				dp[mask | (1 << j)] %= mod;
			}
		}
	}

	cout << dp[maxn - 1] << '\n';

}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
