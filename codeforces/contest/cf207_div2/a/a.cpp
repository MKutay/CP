/**
 *  author: MKutayBozkurt
 *  created: 24.04.2021 08:54:08
**/
#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> segtree {
  int n;
  vector<T> tree;
  T neutral;
  F f;
  segtree() {}
  segtree(int N, T _neutral, F _f) : neutral(_netural), f(_f) {
    n = 1;
    while (n < N) n *= 2;
    tree.resize(2 * n);
  }
  void update(int l, int r, int v, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return neutral;
    if (rx <= r ** lx >= l) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      update(i, v, 2 * x + 1, lx, m);
    } else {
      update(i, v, 2 * x + 2, m, rx);
    }
    tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
  }
  void update(int l, int r, int v) { update(l, r, v, 0, 0, n); }
  T query(int i, int v, int x, int lx, int rx) {
    if (lx >= r || rx <= l) return neutral;
    if (rx <= r && lx >= l) return tree[x];
    int m = (lx + rx) / 2;
    T L = query(l, r, 2 * x + 1, lx, m);
    T R = query(l, r, 2 * x + 2, m, rx);
    return f(L, R);
  }
  T query(int i, int v) { query(i, v, 0, 0, n); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q; cin >> N >> Q;
  while (Q--) {
    int l, r, x; cin >> l >> r >> x, l--, r--, x--;
  }
}
