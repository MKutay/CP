#include "bits/stdc++.h"
using namespace std;

int n;
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  g = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  vector<int> a(n); for (int &x : a) cin >> x;
  int q; cin >> q;
  while (q--) {
    char c; cin >> c;
    if (c == 'F') {
      int u, v; cin >> u >> v;
    } else {
      int u, v, d; cin >> u >> v >> d;
    }
  }
}
