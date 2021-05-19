#include <bits/stdc++.h>
using namespace std;
 
struct segtree {
 
	int size;
	vector<int> mins;
	
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		mins.assign(2 * size, (int) INT_MIN);		
	}
 
	void build(vector<int> &a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < (int) a.size()) {
				mins[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		mins[x] = max(mins[2 * x + 1], mins[2 * x + 2]);
	}
 
	void build(vector<int> &a) {
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx) {
		if (rx - lx == 1) {
			mins[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		} else {
			set(i, v, 2 * x + 2, m, rx);
		}
		mins[x] = max(mins[2 * x + 1], mins[2 * x + 2]);
	}
 
	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}
 
	int calc(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return INT_MIN;
		if (lx >= l && rx <= r) return mins[x];
		int m = (lx + rx) / 2;
		long long s1 = calc(l, r, 2 * x + 1, lx, m);
		long long s2 = calc(l, r, 2 * x + 2, m, rx);
		return max(s1, s2);
	}
 
	int calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}
};
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n;
 
	segtree st;
	st.init(n);
 
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	st.build(a);

  cin >> m;
 
	while (m--) {
		int o;
		cin >> o;
		if (o == 0) {
			int i, v;
			cin >> i >> v; i--;
			st.set(i, v);
		} else {
			int l, r;
			cin >> l >> r; l--, r--;
			cout << st.calc(l, r + 1) << '\n';
		}
	}
	return 0;
}
