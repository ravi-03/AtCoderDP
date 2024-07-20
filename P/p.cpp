#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <stack>
using namespace std;

// #ifndef ONLINE_JUDGE
// #include "../debug.h"
// #else
// #define debug(...) 42
// #endif

// #define int long long
#define ll long long

const int int_max = 2147483647;
const ll int_max2 = 1e12;
const int mod = 1000000007;

int n;
vector<vector<int>> adj;
vector<vector<int>> dp;

int dfs(int u, int p, int col) {
	if (dp[u][col] != -1) {
		return dp[u][col];
	}
	vector<int> children;
	for (int v : adj[u]) {
		if (v == p) continue;
		children.push_back(v);
	}
	if (children.empty()) {
		//leaf
		return 1;
	}
	int ways = 1;
	if (col == 0) {
		for (int v : children) {
			ways = (ll)ways * (((ll)dfs(v, u, 0) + dfs(v, u, 1)) % mod) % mod;
		}
	} else {
		for (int v : children) {
			ways = (ll)ways * dfs(v, u, 0) % mod;
		}
	}
	return dp[u][col] = ways;
}

void runTests() {
	cin >> n;
	adj.resize(n);
	dp.resize(n, vector<int>(2, -1));
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	//assuming 0 as root
	cout << ((ll)dfs(0, -1, 0) + dfs(0, -1, 1)) % mod;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1; 
	while(t--) runTests();
	return 0;
}
