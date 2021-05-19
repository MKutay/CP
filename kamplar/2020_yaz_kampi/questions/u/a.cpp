#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<vector<pair<int, int>>> g;

void solve() {
  cin >> n >> m;
  g = vector<vector<pair<int, int>>>(n);
  for (int i = 0; i < m; i++) {
    int x, y, z; cin >> x >> y >> z, x--, y--;
    g[x].emplace_back(y, z);
    g[y].emplace_back(x, z);
  }
  int u, v; cin >> u >> v, u--, v--;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
