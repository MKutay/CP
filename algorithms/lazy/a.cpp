#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class segtree {
  public:
		int N;
		T neutral;
		vector<T> tree;
    vector<T> delta;
		F f;
		segtree() {}
		segtree(int n, vector<T> &A, T _neutral, F _f) : neutral(_neutral), f(_f) {
			N = 1;
			while (N < n) N *= 2;
			tree.resize(2 * N);
      delta.resize(2 * N);
			build(A, 0, 0, N);
		}
		void build(vector<T> &A, int x, int lx, int rx) {
			if (rx - lx == 1) {
				if (lx < (int) A.size()) tree[x] = A[lx];
				return;
			}
			int m = (lx + rx) / 2;
			build(A, 2 * x + 1, lx, m);
			build(A, 2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
      delta[x] = 0;
		}
		void update(int l, int r, int add, int x, int lx, int rx) {
      if (l > r) return;
      if (l == lx && r == rx) {
        delta[x] += add;
        return;
      }
			int m = (lx + rx) / 2;
      update(l, min(r, m), add, 2 * x + 1, lx, m);
      update(max(l, m + 1), r, add, 2 * x + 2, m, rx);
			tree[x] = f(tree[2 * x + 1] + delta[2 * x + 1], tree[2 * x + 2] + delta[2 * x + 2]);
		}
		void update(int l, int r, int add) { update(l, r + 1, add, 0, 0, N); }
		T query(int l, int r, int x, int lx, int rx) {
			if (lx >= r || rx <= l) return neutral;
			if (rx <= r && lx >= l) return tree[x] + delta[x];
			int m = (lx + rx) / 2;
			T L = query(l, r, 2 * x + 1, lx, m);
			T R = query(l, r, 2 * x + 2, m, rx);
			return f(L, R);
		}
		T query(int l, int r) { return query(l, r + 1, 0, 0, N); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  int M; cin >> M;
  segtree st(N, A, 0, [&](int a, int b) {
    return max(a, b);
  });

  while (M--) {
    int op; cin >> op;
    if (op == 1) {
      int l, r; cin >> l >> r, l--, r--;
      cout << st.query(l, r) << '\n';
    } else {
      int l, r, add; cin >> l >> r >> add, l--, r--;
      st.update(l, r, add);
    }
  }
}
