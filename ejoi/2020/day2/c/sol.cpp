#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<vector<int>> v;
vector<vector<int>> vis;
 
 
int bfs(pair<int, int> p) {
	queue<pair<int, pair<int, int>>> q;
	q.push({p.first, {p.second, 0}});
	vector<vector<int>> vis2(2 * n + 1, vector<int>(2 * m + 1));
	while (q.size()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();
		if (x < 0 || y < 0 || x >= 2 * n + 1 || y >= 2 * m + 1 || vis2[x][y] || v[x][y]) continue;
		vis2[x][y] = 1;
		q.push({x - 1, {y, z + 1}});
		q.push({x + 1, {y, z + 1}});
		q.push({x, {y - 1, z + 1}});
		q.push({x, {y + 1, z + 1}});
	}
	int ans = 0;
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * m + 1; j++) {
			ans += vis2[i][j];
			vis[i][j] |= vis2[i][j];
		}
	}
	return ans;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m));
	vector<vector<int>> b(n, vector<int>(m + 1));
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			a[i][j] = c - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m + 1; j++) {
			char c; cin >> c;
			b[i][j] = c - '0';
		}
	}
 
	v = vector<vector<int>>(2 * n + 1, vector<int>(2 * m + 1));
	vis = vector<vector<int>>(2 * n + 1, vector<int>(2 * m + 1));
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * m + 1; j++) {
			if (i & 1) {
				if (j & 1) {
					v[i][j] = 0;
				} else {
					v[i][j] = b[i / 2][j / 2];
				}
			} else {
				if (j & 1) {
					v[i][j] = a[i / 2][j / 2];
				} else {
					v[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * m + 1; j++) {
			//cerr << v[i][j];
		}
		//cerr << '\n';
	}
	vector<pair<int, pair<int, int>>> comp;
	for (int i = 0; i < 2 * n + 1; i++) {
		for (int j = 0; j < 2 * m + 1; j++) {
			if (v[i][j] || vis[i][j]) continue;
			int bf = bfs({i, j});
			comp.push_back({bf, {i, j}});
		}
	}
	sort(comp.begin(), comp.end());
	int T = 0, A = 0;
	for (int i = 0; i < (int) comp.size(); i++) {
		//cerr << comp[i] << '\n';
		int x = comp[i].second.first, y = comp[i].second.second;
		if (comp[i].first == 1 && a[x / 2][y / 2] && a[x / 2 + 1][y / 2] && b[x / 2][y / 2] && b[x / 2][y / 2 + 1]) continue;
		if (comp[i].first == 1) {
			if (i & 1) {
				T++;
			} else {
				A++;
			}
			continue;
		}
		if (i & 1) {
			if (comp[i].first == 2) {
				A += 2;
			} else {
				A += (comp[i].first - 1) / 2;
			}
		} else {
			if (comp[i].first == 2) {
				T += 2;
			} else {
		  	T += (comp[i].first - 1) / 2;
		  }
		}
	}
	cout << A - T << '\n';
}
 
/*
111111111
100000000
101111111
101000001
101011101
001010100
111011111
000010101
111111111
*/