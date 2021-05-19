#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;
vector<vector<pair<int, int>>> mp2(200);

int bfs(int i, int j) {
  queue<pair<int, pair<int, int>>> q;
  vector<vector<int>> vis(n, vector<int>(m));
  q.push({i, {j, 0}});
  while (q.size()) {
    int x = q.front().first;
    int y = q.front().second.first;
    int z = q.front().second.second;
    q.pop();

    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || a[x][y] == '#') continue;
    vis[x][y] = 1;

    if (a[x][y] == 'G') {
      return z;
    }

    if (!(x + 1 < 0 || y < 0 || x + 1 >= n || y >= m || vis[x + 1][y] || a[x + 1][y] == '#')) q.push({x + 1, {y, z + 1}});
    if (!(x - 1 < 0 || y < 0 || x - 1 >= n || y >= m || vis[x - 1][y] || a[x - 1][y] == '#')) q.push({x - 1, {y, z + 1}});
    if (!(x < 0 || y + 1 < 0 || x >= n || y + 1 >= m || vis[x][y + 1] || a[x][y + 1] == '#')) q.push({x, {y + 1, z + 1}});
    if (!(x < 0 || y - 1 < 0 || x >= n || y - 1 >= m || vis[x][y - 1] || a[x][y - 1] == '#')) q.push({x, {y - 1, z + 1}});

    if (a[x][y] < 'a' || a[x][y] > 'z') continue;

    for (pair<int, int> node : mp2[a[x][y] - 'a']) {
      if (!vis[node.first][node.second]) q.push({node.first, {node.second, z + 1}});
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  a = vector<vector<char>>(n, vector<char>(m));
  int x, y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        x = i, y = j;
      }
      if (a[i][j] != '#' && a[i][j] != '.' && a[i][j] != 'S' && a[i][j] != 'G') {
        mp2[a[i][j] - 'a'].emplace_back(i, j);
      }
    }
  }
  cout << bfs(x, y) << '\n';
}
