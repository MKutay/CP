#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

struct segTree {
	vector<int> tree, ar;
	int nef = 1;

	void init(vector<int> a, int af) {
		tree = vector<int>(n * 4 + 1);
		ar = a;
		nef = af;
		build(1, 1, a.size());
	}

	void build(int node, int left, int right) {
		if (left == right) {
			tree[node] = ar[left];
			return;
		}
		int m = (left + right) + 1;
		build(node * 2, left, m);
		build(node * 2 + 1, m + 1, right);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}

	void update(int node, int left, int right, int in, int val) {
		if (left > in || right < in) return;
		if (left == in && right == in) {
			tree[node] = val;
			return;
		}
		int m = (left + right) / 2;
		update(node * 2, left, m, in, val);
		update(node * 2 + 1, m + 1, right, in, val);
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}

	int query(int node, int left, int right, int l, int r) {
		if (left > r || right < l) return 0;
		if (left >= l && right <= r) return tree[node];
		int m = (left + right) / 2;
		int L = query(node * 2, left, m, l, r);
		int R = query(node * 2 + 1, m + 1, right, l, r);
		return min(L, R);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	a = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	segTree st;
	st.init(a, 0);
	int q;
	cin >> q;
	while (q--) {
		int o, c, d;
		cin >> o >> c >> d;
		if (o == 1)
			st.update(1, 1, n, c + 1, d);
		else
			cout << st.query(1, 1, n, c + 1, d) << '\n';
	}
}
