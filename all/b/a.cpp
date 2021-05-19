#include <bits/stdc++.h>
using namespace std;
#define int long long

struct segtree {

	int func(int a, int b) {
		return a + b;
	}
	int size;
	vector<int> tree;
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		tree = vector<int>(4 * size);
	}
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) a.size()) {
				tree[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		tree[x] = func(tree[2 * x + 1], tree[2 * x + 2]);
	}
	void build(vector<int> &a) {
		build(a, 0, 0, size);
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
		tree[x] = func(tree[2 * x + 1], tree[2 * x + 2]);
	}
	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}
	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return 0;
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		long long s1 = query(l, r, 2 * x + 1, lx, m);
		long long s2 = query(l, r, 2 * x + 2, m, rx);
		return func(s1, s2);
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "slm" << endl;
	st.build(a);
	cout << "slm2" << endl;

	while (m--) {
		int o;
		cin >> o;
		if (o == 2) {
			int i, v; cin >> i >> v; i--;
			st.update(i, v);
		} else {
			int l, r; cin >> l >> r, l--, r--;
			cout << st.query(l, r) << '\n';
		}
	}

	return 0;
}

