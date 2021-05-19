#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("metal.gir", "r", stdin);
  freopen("metal.cik", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    if (y < x) swap(x, y);
    g[x].emplace_back(y);
  }
  vector<int> parents(N);
  set<int> roots;

  for (int i = 0; i < N; i++) {
    parents[i] = i;
  }

  function<int(int)> find_parent = [&](int node) {
    if (node == parents[node]) return node;
    return parents[node] = find_parent(parents[node]);
  };

  int mn = N - 1;

  function<int(int)> solve = [&](int node) {
    for (int other_node : g[node]) {
      int parent = find_parent(other_node);
      if (other_node != parent) {
        mn = min(mn, parent - 1);
      }
      parents[parent] = node;
      roots.erase(parent);
    }
    int res = mn;
    if (roots.size()) {
      res = min(res, *roots.begin() - 1);
    }
    roots.insert(node);
    return res - node + 1;
  };

  long long ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    ans += solve(i);
  }
  cout << ans << '\n';
}
