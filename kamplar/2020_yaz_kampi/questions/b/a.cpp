#include <bits/stdc++.h>
using namespace std;

int n, m;

int bfs(vector<vector<char>> a) {
  deque<pair<int, pair<int, int>>> d;
	vector<vector<int>> vis(n, vector<int>(m));
	d.push_front({0, {0, 0}});
	while (d.size()) {
		int x = d.front().first;
		int y = d.front().second.first;
		int z = d.front().second.second;
		d.pop_front();
    if (x == n - 1 && y == m - 1) {
      return z;
    }
		if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) continue;
		vis[x][y] = 1;

    if (x < n - 1 && a[x][y] == a[x + 1][y]) d.push_front({x + 1, {y, z}});
    else d.push_back({x + 1, {y, z + 1}});
    if (x > 0 && a[x][y] == a[x - 1][y]) d.push_front({x - 1, {y, z}});
    else d.push_back({x - 1, {y, z + 1}});
    if (y < m - 1 && a[x][y] == a[x][y + 1]) d.push_front({x, {y + 1, z}});
    else d.push_back({x, {y + 1, z + 1}});
    if (y > 0 && a[x][y] == a[x][y - 1]) d.push_front({x, {y - 1, z}});
    else d.push_back({x, {y - 1, z + 1}});
	}
	return -1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    cout << bfs(a) << '\n';
  }
}
