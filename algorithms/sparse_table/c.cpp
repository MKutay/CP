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

struct sparseTable {
  int N, K;
  vector<vector<int>> table;
  vector<vector<int>> ind;
  void build(vector<int> a) {
    N = a.size();
    K = 31 - __builtin_clz(N);

    table = vector<vector<int>>(K + 1, vector<int>(N));
    ind = vector<vector<int>>(K + 1, vector<int>(N));
    for (int i = 0; i < N; i++) {
      table[0][i] = a[i];
      ind[0][i] = i;
    }
    for (int k = 1; k <= K; k++) {
      for (int i = 0; i < N; i++) {
        int j = i + (1 << (k - 1));
        if (j < N) {
          if (table[k - 1][i] < table[k - 1][i + (1 << (k - 1))]) {
            table[k][i] = table[k - 1][i];
            ind[k][i] = ind[k - 1][i];
          } else {
            table[k][i] = table[k - 1][i + (1 << (k - 1))];
            ind[k][i] = ind[k - 1][i + (1 << (k - 1))];
          }
        }
      }
    }
  }
  int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    if (table[k][l] < table[k][r - (1 << k) + 1]) {
      return ind[k][l];
    } else {
      return ind[k][r - (1 << k) + 1];
    }
  }
};

struct LCA {
  sparseTable st;

};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> a(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    a[x].emplace_back(y);
  }
  LCA lca;
  lca.build(a, N);
  int q; cin >> q;
  while (q--) {
    int x, y; cin >> x >> y, x--, y--;
    cout << lca.query(x, y) << '\n';
  }
}
