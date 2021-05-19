#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> g(N + 1);
    for (int i = 0; i < M; i++) {
      int x, y, z; cin >> x >> y >> z, x--, y--;
      g[x].emplace_back(y, z);
      g[y].emplace_back(x, z);
    }

    if (K != 0) assert(false);

    function<int()> mst = [&]() {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> vis(N);
      pq.push({0, 0});
      int sum = 0;
      while (pq.size()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if (vis[y]) continue;
        vis[y] = 1;
        sum += x;
        for (auto node : g[y]) {
          if (!vis[node.first]) {
            pq.push({node.second, node.first});
          }
        }
      }
      return sum;
    };
    cout << mst() << '\n';
  }
}
