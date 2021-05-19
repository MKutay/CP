#include "bits/stdc++.h"
using namespace std;

int n;
vector<vector<int>> g;
string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  g = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v, u--, v--;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  cin >> s;
}
