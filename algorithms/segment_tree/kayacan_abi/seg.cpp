#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

struct segtree {
	int size;
	vector<int> tree;
	void init(int m) {
		size = 1;
		while (size < m) size *= 2;
		tree = vector<int>(size);
	}
	void build(int k, int l, int r) {
		if (r - l == 1) {
			if (l < (int) a.size()) {
				tree[k] = a[l];
			}
			return;
		}
		int m = (l + r) / 2;
		build(2 * k, l, m);
		build(2 * k + 1, m + 1, r);
		tree[k] = min(tree[2 * k], tree[2 * k + 1]);
	}
	void build() {
		build(1, 1, size);
	}
	int query(int l, int r, int k, int lk, int rk) {
		if (lk > r || rk < l) return INT_MAX;
		if (lk >= l && rk <= r) {
			return tree[k];
		}
		int m = (lk + rk) / 2;
		int s1 = query(l, r, 2 * k, lk, m);
		int s2 = query(l, r, 2 * k + 1, m + 1, rk);
		return min(s1, s2);
	}
	int query(int l, int r) {
		return query(l, r, 1, 1, size);
	}
	void update(int i, int v, int k, int lk, int rk) {
		if (rk - lk == 1) {
			tree[k] = v;
			return;
		}
		int m = (lk + rk) / 2;
		if (i < m) {
			update(i, v, 2 * k, lk, m);
		} else {
			update(i, v, 2 * k + 1, m + 1, rk);
		}
		tree[k] = min(tree[2 * k], tree[2 * k + 1]);
	}
	void update(int i, int v) {
		update(i, v, 1, 1, n);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	a = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	segtree st;
	st.init(n);
	st.build();
	int q; cin >> q;
	while (q--) {
		int o;
		cin >> o;
		if (o == 1) {
			int l, r;
			cin >> l >> r;
			cout << st.query(l, r) << '\n';
		} else {
			int i, v;
			cin >> i >> v;
			st.update(i, v);
		}
	}
	return 0;
}
