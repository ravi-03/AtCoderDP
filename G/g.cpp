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

vector<bool> visited;
vector<int> indeg;

void dfs(int src, vector<int> &dist, vector<vector<int>> &adj) {

	visited[src] = true;

	for(int v : adj[src]) {
		indeg[v]--;
		dist[v] = max(dist[v], dist[src] + 1);
		if(indeg[v] == 0) {
			dfs(v, dist, adj);
		}
	}
}

void runTests() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);

	indeg.resize(n, 0);

	for(int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		indeg[v]++;
	}

	vector<int> dist(n, 0); //maximum dist to reach node i

	visited.resize(n, false);

	for(int i = 0; i < n; i++) {
		if(indeg[i] == 0 && visited[i] == false) {
			dfs(i, dist, adj);
		}
	}

	cout << *max_element(dist.begin(), dist.end()) << '\n';
}

int32_t main() {
	fastIO();
	int t = 1;
	while(t--) runTests();
	return 0;
}
