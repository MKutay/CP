#include <bits/stdc++.h>
using namespace std;

struct segtree {

	int func(int a, int b) {
		return a + b;
	}

	int size;
	vector<int> operations;
	
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		operations = vector<int>(size);
	}

	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}

	int add(int l, int r, int v, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return INT_MAX;
		if (lx >= l && rx <= r) return operations[x];
		int m = (lx + rx) / 2;
		long long s1 = query(l, r, 2 * x + 1, lx, m);
		long long s2 = query(l, r, 2 * x + 2, m, rx);
		return func(s1, s2);
	}

	int add(int l, int r, int v) {
		return query(l, r, v, 0, 0, size);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) a.size()) {
				operations[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		operations[x] = func(operations[2 * x + 1], operations[2 * x + 2]);
	}

	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}

	void update(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			operations[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			update(i, v, 2 * x + 1, lx, m);
		} else {
			update(i, v, 2 * x + 2, m, rx);
		}
		operations[x] = func(operations[2 * x + 1], operations[2 * x + 2]);
	}

	void update(int i, int v) {
		update(i, v, 0, 0, size);
	}

	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return INT_MAX;
		if (lx >= l && rx <= r) return operations[x];
		int m = (lx + rx) / 2;
		long long s1 = query(l, r, 2 * x + 1, lx, m);
		long long s2 = query(l, r, 2 * x + 2, m, rx);
		return func(s1, s2);
	}

	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	st.build(a);

	while (m--) {
		int o;
		cin >> o;
		if (o == 1) {
			int l, r, v; cin >> l >> r >> v;
			cout << st.add(l, r, v) << '\n';
			st.set(l, r, v);
		} else {
			int i; cin >> i;
			cout << st.get(i) << '\n';
		}
	}

	return 0;
}

