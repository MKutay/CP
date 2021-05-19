#include <bits/stdc++.h>
using namespace std;

struct segtree {
	int n;
	vector<long long> tree;

	void init(int N) {
		n = 1;
		while (n < N) n *= 2;
		tree.assign(2 * n, 0ll);
	}

	void build(vector<int> &A, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) A.size()) tree[x] = A[lx];
			return;
		}
		int m = (lx + rx) / 2;
		build(A, 2 * x + 1, lx, m);
		build(A, 2 * x + 2, m, rx);
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	void build(vector<int> &A) {
		build(A, 0, 0, n);
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
		tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
	}
	void update(int i, int v) {
		update(i, v, 0, 0, n);
	}

	long long query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		long long L = query(l, r, 2 * x + 1, lx, m);
		long long R = query(l, r, 2 * x + 2, m, rx);
		return L + R;
	}
	long long query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

int main() {
	int N, M; cin >> N >> M;
	
	vector<int> A(N); for (int &x : A) cin >> x;

	segtree st;
	st.init(N);
	st.build(A);

	while (M--) {
		int O; cin >> O;
		if (O == 1) {
			int X, Y; cin >> X >> Y;
			st.update(X, Y);
		} else {
			int L, R; cin >> L >> R;
			cout << st.query(L, R) << '\n';
		}
	}
}
