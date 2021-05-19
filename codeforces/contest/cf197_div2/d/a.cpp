/**
 *  author: MKutayBozkurt
 *  created: 23.12.2020 22:00:35
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

int nn;

struct segtree {
  vector<int> tree;
  int n;

  void init(int N) {
    n = 1;
    while (n < N) n *= 2;
    tree.assign(2 * n, 0ll);
  }

  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < a.size()) tree[x] = a[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    int lg = log2(x + 1);
    if ((nn - lg) & 1) tree[x] = tree[2 * x + 1] | tree[2 * x + 2];
    else tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
  }
  void build(vector<int> &a) {
    build(a, 0, 0, n);
  }
  
  void update(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      update(i, v, 2 * x + 1, lx, m);
    } else {
      update(i, v, 2 * x + 2, m, rx);
    }
    int lg = log2(x + 1);
    if ((nn - lg) & 1) tree[x] = tree[2 * x + 1] | tree[2 * x + 2];
    else tree[x] = tree[2 * x + 1] ^ tree[2 * x + 2];
  }
  void update(int i, int v) {
    update(i, v, 0, 0, n);
  }

  int query() {
    debug() << imie(tree) imie(nn);
    return tree[0];
  }
};

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  nn = n;
  vector<int> a(1 << n);
  for (int &x : a) cin >> x;
  segtree st;
  st.init(1ll << n);
  st.build(a);
  debug() << imie(st.query());
  while (m--) {
    int i, v; cin >> i >> v; i--;
    st.update(i, v);
    cout << st.query() << '\n';
  }
  debug() << imie(a);
}
