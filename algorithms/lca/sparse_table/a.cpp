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

template<typename T, typename F = function<T(const T&, const T&)>> class sparseTable {
  public:
    int sz, lg;
    vector<vector<T>> table;
    F cal;
    sparseTable() { }
    sparseTable(vector<T> v, F _cal) : cal(_cal) {
      sz = (int) v.size();
      lg = 32 - __builtin_clz(sz);
      table.resize(lg);
      table[0] = v;
      for (int i = 1; i < lg; ++i) {
        table[i].resize(sz - (1 << i) + 1);
        assert(sz - (1 << i) + 1 >= 0);
        for (int j = 0; j < (int) table[i].size(); ++j) {
          table[i][j] = cal(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
      }
    }
    T query(T l, T r) {
      assert(l >= 0 && r < sz && l <= r);
      int clg = 31 - __builtin_clz(r - l + 1);
      return cal(table[clg][l], table[clg][r - (1 << clg) + 1]);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  vector<array<int, 2>> pos(N);
  vector<int> tour, d(N);
  function<void(int, int)> dfs = [&](int v, int parent) {
    pos[v][0] = pos[v][1] = tour.size();
    tour.emplace_back(v);
    for (auto node : g[v]) {
      if (node == parent) continue;
      d[node] = d[v] + 1;
      dfs(node, v);
      pos[v][1] = tour.size();
      tour.emplace_back(v);
    }
  };
  dfs(0, -1);
  sparseTable<int> st(tour, [&](int x, int y) {
    return (d[x] < d[y] ? x : y);
  });
  auto query = [&](int x, int y) {
    if (pos[x][0] > pos[y][0]) swap(x, y);
    if (pos[x][1] >= pos[y][1]) return x;
    return st.query(pos[x][1], pos[y][0]);
  };

  int M; cin >> M;
  while (M--) {
    int x, y; cin >> x >> y, x--, y--;
    cout << query(x, y) + 1 << '\n';
  }
}
