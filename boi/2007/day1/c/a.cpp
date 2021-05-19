#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

struct segtree {
	int size;
	int op;
	vector<int> tree;
	int func(int a, int b) {
		if (op == 1) return min(a, b);
		else if (op == 2) return max(a, b);
		else cout << "oops\n";
		return 123123;
	}
	void init(int n, int o) {
		size = 1;
		while (size < n)  size *= 2;
		tree = vector<int>(size * 2);
		op = o;
	}
	void build(vector<int> a, int x, int lx, int rx) {
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
	void build(vector<int> a) {
		build(a, 0, 0, size);
	}
	int query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) {
			if (op == 1) {
				return INT_MAX;
			} else if (op == 2) {
				return INT_MIN;
			}
		}
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		int s1 = query(l, r, 2 * x + 1, lx, m);
		int s2 = query(l, r, 2 * x + 2, m, rx);
		return func(s1, s2);
	}
	int query(int l, int r) {
		return query(l, r, 0, 0, size);
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, c; cin >> n >> m >> c;
	vector<int> a(n); cin >> a;
	segtree st1, st2;
	st1.init(n, 1);
	st2.init(n, 2);
	st1.build(a);
	st2.build(a);
	bool flag = 1;
	for (int i = 0; i <= n - m; i++) {
		int mn = st1.query(i, i + m);
		int mx = st2.query(i, i + m);
		if (mx - mn <= c) {
			cout << i + 1 << '\n';
			flag = 0;
		}
	}
	if (flag) {
		cout << "NONE\n";
	}
}
