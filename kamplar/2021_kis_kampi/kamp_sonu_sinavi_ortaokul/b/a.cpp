/**
 *  author: MKutayBozkurt
 *  created: 10.04.2021 09:25:15
**/
#include <bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << (it == d.b ? "" : ", ") << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> g(N + 1);
    vector<pair<pair<int, int>, int>> inp(M + 1);
    for (int i = 0; i < M; i++) {
      int x, y, z; cin >> x >> y >> z, x--, y--;
      inp[i] = {{z, x}, y};
    }

    sort(inp.rbegin(), inp.rend());

    int k = K, tmp = 0;
    for (int i = 0; i < min(k - 1, M); i++) {
      tmp = k;
      if (inp[i].first.second == inp[i].second) {
        k++;
        continue;
      }
      debug() << imie(inp[i]);
      inp[i].first.first = 0;
      inp[i + 1].first.first++;
    }

    debug() << imie(tmp);
    
    if (K != 0) { 
      inp[tmp].first.first = 0;

      int flag = 0;
      for (int i = 0; i < M; i++) {
        if (inp[i].first.second == inp[i].second) {
          inp[i].first.first++;
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        inp[M - 1].first.first++;
      }
    }

    for (int i = 0; i < M; i++) {
      int x = inp[i].first.second;
      int y = inp[i].second;
      int z = inp[i].first.first;
      g[x].emplace_back(y, z);
      g[y].emplace_back(x, z);
    }

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
