#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int N;
	int neutral;
	vector<int> tree;
	vector<int> delta;
	int f(int a, int b) {
		return max(a, b);
	}
	void init(int n, vector<int> A, int _neutral) {
		neutral = _neutral;
		N = 1;
		while (N < n) N *= 2;
		tree.resize(2 * N);
		delta.resize(2 * N);
	}
	void update(int l, int r, int add, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return;
		if (lx >= l && rx <= r) {
			delta[x] += add;
			tree[x] += add;
			return;
		}
		int m = (lx + rx) / 2;
		update(l, r, add, 2 * x + 1, lx, m);
		update(l, r, add, 2 * x + 2, m, rx);
		tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]) + delta[x];
	}
	void update(int l, int r, int add) { update(l, r + 1, add, 0, 0, N); }
	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return neutral;
		if (rx <= r && lx >= l) return tree[x];
		int m = (lx + rx) / 2;
		int L = query(l, r, 2 * x + 1, lx, m);
		int R = query(l, r, 2 * x + 2, m, rx);
		return f(L, R) + delta[x];
	}
	int query(int l, int r) { return query(l, r + 1, 0, 0, N); }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
	freopen("segment.gir", "r", stdin);
	freopen("segment.cik", "w", stdout);
  int M; cin >> M;
  int N = 1e6;
  vector<int> A(N + 1, 0);
	segtree st;
	st.init(N, A, 0);
  while (M--) {
    char op; cin >> op;
    if (op == 'I') {
      int a, b; cin >> a >> b, a--, b--;
      st.update(a, b, 1);
    } else {
      int a, b; cin >> a >> b, a--, b--;
      cout << st.query(a, b) << '\n';
    }
  }
}
