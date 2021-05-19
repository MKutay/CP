#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> vis;
bool ok;

void dfs(int node) {
  if (g[node].size() != 2) ok = 0;
  if (vis[node]) return;
  vis[node] = 1;
  for (auto x : g[node]) {
    dfs(x);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  g = vector<vector<int>>(n);
  vis = vector<int>(n);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y, x--, y--;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    ok = 1;
    dfs(i);
    if (ok) ans += 1;
  }
  cout << ans << '\n';
}
