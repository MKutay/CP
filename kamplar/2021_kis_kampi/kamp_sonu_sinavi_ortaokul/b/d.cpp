/**
 *  author: MKutayBozkurt
 *  created: 10.04.2021 09:25:15
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> g(N + 1);
    vector<pair<pair<int, int>, int>> inp;
    int flag = 0;
    int m = 0;
    for (int i = 0; i < M; i++) {
      int x, y, z; cin >> x >> y >> z, x--, y--;
      if (x == y) {
        flag = 1;
        continue;
      }
      m++;
      inp.push_back({{z, x}, y});
      g[x].emplace_back(y, z);
      g[y].emplace_back(x, z);
    }

    if (K == N - 1) {
      if (M == N - 1) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
      continue;
    }

    vector<int> edges;

    function<int()> mst = [&]() {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> vis(N + 1);
      pq.push({0, 0});
      int sum = 0;
      while (pq.size()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        if (vis[y]) continue;
        vis[y] = 1;
        sum += x;
        edges.emplace_back(x);
        for (auto node : g[y]) {
          if (!vis[node.first]) {
            pq.push({node.second, node.first});
          }
        }
      }
      return sum;
    };
    mst();

    sort(edges.rbegin(), edges.rend());

    for (int i = 0; i < K; i++) {
      edges[i] = 0;
    }
    int ans = 0;
    for (auto x : edges) ans += x;
    if (K == 0) {
      cout << ans << '\n';
      continue;
    }
    if (M == N - 1 || (int) edges.size() - 1 == M || (int) edges.size() - 1 == m) {
      ans++;
    }
    cout << ans << '\n';
  }
}
