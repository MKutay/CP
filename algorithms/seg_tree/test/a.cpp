#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class segtree {
	public:
		int N;
		T neut;
		F f;
		vector<T> tree;
		segtree() {}
		segtree(int n, vector<T> A, T _neut, F _f) : neut(_neut), f(_f) {
			N = 1;
			while (N < n) N *= 2;
			tree.resize(N * 2);
			build(A, 0, 0, N);
		}
		void build(vector<T> A, int x, int lx, int rx) {
			if (rx - lx == 1) {
				if (lx < (int) A.size()) tree[x] = A[lx];
				return;
			}
			int m = (lx + rx) / 2;
			build(A, 2 * x + 1, lx, m);
			build(A, 2 * x + 2, m, rx);
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
			if (rx <= l || lx >= r) return neut;
			if (rx <= r && lx >= l) return tree[x];
			int m = (lx + rx) / 2;
			int L  = query(l, r, 2 * x + 1, lx, m);
			int R = query(l, r, 2 * x + 2, m, rx);
			return f(L, R);
		}
		T query(int l, int r) { return query(l, r, 0, 0, N); }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M; cin >> N >> M;
	vector<long long> A(N); for (auto &x : A) cin >> x;
	segtree<long long> st(N, A, 0, [&](long long a, long long b) {
		return a + b;
	});
	while (M--) {
		int O; cin >> O;
		if (O == 2) {
			int L, R; cin >> L >> R;
			cout << st.query(L, R) << '\n';
		} else {
			int I, V; cin >> I >> V;
			st.update(I, V);
		}
	}
}
