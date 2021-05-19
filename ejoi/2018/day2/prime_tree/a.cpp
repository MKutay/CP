#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int n;
vector<vector<int>> v;
vector<int> vis;
vector<int> ans;
int sum;

void dfs(int i) {
	if (vis[i]) return;
	vis[i] = 1;
	ans[i] = sum++;
	for (auto node : v[i]) {
		dfs(node);
	}
}

void solve() {
	cin >> n;
	v = vector<vector<int>>(n);
	vis = vector<int>(n);
	ans = vector<int>(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y; cin >> x >> y, x--, y--;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}

