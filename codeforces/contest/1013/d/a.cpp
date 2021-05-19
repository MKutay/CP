#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int n, m, q;
vector<vector<int>> v;
vector<int> vis;

void dfs(int i) {
	if (vis[i]) return;
	vis[i] = 1;
	for (auto node : v[i]) {
		dfs(node);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	v.resize(n + m);
	vis.resize(n + m);
	for (int i = 0; i < q; i++) {
		int x, y; cin >> x >> y, x--, y--;
		y += n;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	int ans = 0;
	for (int i = 0; i < n + m; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << '\n';
	return 0;
}

