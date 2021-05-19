#include <bits/stdc++.h>
using namespace std;
 
struct item {
	long long seg, pref, suf, sum;
};
 
struct segtree {
 
	int size;
	vector<item> mins;
	item N_ELEMENT = {0, 0, 0, 0};
 
	item merge(item a, item b) {
		return {
			max({a.seg, b.seg, a.suf + b.suf}),
			max(a.pref, a.sum + b.pref),
			max(b.suf, b.sum + a.sum),
			a.sum + b.sum
		};
	}
 
	item single(int v) {
		if (v > 0) {
			return {v, v, v, v};
		} else {
			return {0, 0, 0, v};
		}
	}
 
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		mins.resize(2 * size);		
	}
 
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) a.size()) {
				mins[x] = single(a[lx]);
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		mins[x] = merge(mins[2 * x + 1], mins[2 * x + 2]);
	}
 
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			mins[x] = single(v);
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		mins[x] = merge(mins[2 * x + 1], mins[2 * x + 2]);
	}
 
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
 
	item calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return N_ELEMENT;
		if (lx >= l && rx <= r) return mins[x];
		int m = (lx + rx) / 2;
		item s1 = calc(l, r, 2 * x + 1, lx, m);
		item s2 = calc(l, r, 2 * x + 2, m, rx);
		return merge(s1, s2);
	}
 
	item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
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
	cout << st.calc(0, n).seg << '\n';
	while (m--) {
		int i, v; cin >> i >> v;
		st.set(i, v);
		cout << st.calc(0, n).seg << '\n';
	}
	return 0;
}
