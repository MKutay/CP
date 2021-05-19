/**
 *  author: MKutayBozkurt
 *  created: 01.03.2021 20:18:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<int>> g(N + M + 5);
  for (int i = 0; i < Q; i++) {
    int X, Y; cin >> X >> Y, X--, Y--;
    Y += N;
    g[X].emplace_back(Y);
    g[Y].emplace_back(X);
  }
  vector<int> vis(N + M + 5);
  function<void(int)> dfs = [&](int node) {
    if (vis[node]) return;
    vis[node] = 1;
    for (auto v : g[node]) {
      dfs(v);
    }
  };
  int ans = -1;
  for (int i = 0; i < N + M; i++) {
    if (vis[i]) continue;
    dfs(i);
    ans++;
  }
  cout << ans << '\n';
}
