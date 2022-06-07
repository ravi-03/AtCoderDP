#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fastIO() {ios_base::sync_with_stdio(false); cin.tie(NULL);}

double final_ans = 0;
int n;
vector<double> p;

void dp(int cur_ind, int numOfHeads, double ans) {
	if(cur_ind == n) {
		if(numOfHeads > n / 2) {
			final_ans += ans;
		}
	} else {
		//pick
		dp(cur_ind + 1, numOfHeads + 1, ans * p[cur_ind]);
		//don't pick
		dp(cur_ind + 1, numOfHeads, ans * (1 - p[cur_ind]));
	}
}

void runTests() {
	cin >> n;
	p.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	dp(0, 0, 1.0);
	cout << fixed << setprecision(10) << final_ans << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
