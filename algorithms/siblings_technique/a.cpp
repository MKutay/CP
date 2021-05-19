#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> g(N + 1);
  vector<vector<int>> parent(N + 1);
  for (int i = 0; i < N; i++) {
    int x, y; cin >> x >> y, x--, y--;
    g[x].emplace_back(y);
    parent[y].emplace_back(x);
  }
}
