#include <bits/stdc++.h>

using namespace std;

int prim(vector<vector<pair<int, int>>> v, int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> vis(n);
	pq.push({0, 0});
	int sum = 0;
	while (pq.size()) {
		auto [x, y] = pq.top();
		pq.pop();
		if (vis[y]) continue;
		vis[y] = 1;
		sum += x;
		for (auto node : v[y]) {
			if (!vis[node.first]) {
				pq.push({node.second, node.first});
			}
		}
	}
	return sum;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(nullptr); cout.tie(0); cerr.tie(0);
  int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c, a--, b--;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	cout << prim(v, n) << endl;
  return 0;
}

