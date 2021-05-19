#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class segtree {
  public:
		int N;
		T neutral;
		vector<T> tree;
		F f;
		segtree() {}
		segtree(int n, T _neutral, F _f) : neutral(_neutral), f(_f) {
			N = 1;
			while (N < n) N *= 2;
			tree.resize(2 * N);
			build(0, 0, N);
		}
		void build(int x, int lx, int rx) {
			if (rx - lx == 1) {
        tree[x] = 0;
				return;
			}
			int m = (lx + rx) / 2;
			build(2 * x + 1, lx, m);
			build(2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
		}
		void update(int i, int v, int x, int lx, int rx) {
			if (rx - lx == 1) {
				tree[x] = v;
				return;
			}
			int m = (lx + rx) / 2;
			if (i < m) update(i, v, 2 * x + 1, lx, m);
			else update(i, v, 2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
		}
		void update(int i, int v) { update(i, v, 0, 0, N); }
		T query(int l, int r, int x, int lx, int rx) {
			if (lx >= r || rx <= l) return neutral;
			if (rx <= r && lx >= l) return tree[x];
			int m = (lx + rx) / 2;
			T L = query(l, r, 2 * x + 1, lx, m);
			T R = query(l, r, 2 * x + 2, m, rx);
			return f(L, R);
		}
		T query(int l, int r) { return query(l, r, 0, 0, N); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q; cin >> N >> Q;
  segtree st(N, 0, [&](int a, int b) {
    return a + b;
  });
  while (Q--) {
    char op; cin >> op;
    if (op == 'F') {
      int i; cin >> i, i--;
      if (st.query(i, i) == 1) st.update(i, 0);
      else st.update(i, 1);
    } else {
      int l, r; cin >> l >> r, l--, r--;
      cout << st.query(l, r) << '\n';
    }
  }
}
