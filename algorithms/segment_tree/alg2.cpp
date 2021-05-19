#include <bits/stdc++.h>
using namespace std;

vector<int> ar;
int n;

struct segTree {
	
	vector<int> lo, hi, minim, delta, v;

	void init(int m) {
		lo = vector<int>(4 * m + 1);
		hi = vector<int>(4 * m + 1);
		minim = vector<int>(4 * m + 1);
		delta = vector<int>(4 * m + 1);
		build(1, 0, m - 1);
	}
	
	void build(int i, int a, int b) {
		lo[i] = a;
		hi[i] = b;
		if (a == b) return;
		int m = (a + b) / 2;
		build(2 * i, a, m);
		build(2 * i + 1, m + 1, b);
	}
	
	void prop(int i) {
		delta[2 * i] += delta[i];
		delta[2 * i + 1] += delta[i];
		delta[i] = 0;
	}

	void update(int i) {
		minim[i] = min(minim[2 * i] + delta[2 * i], minim[2 * i + 1] + delta[2 * i + 1]);
	}

	void increment_main(int i, int a, int b, int val) {
		if (b < lo[i] || hi[i] < a) return;
		if (a <= lo[i] && hi[i] <= b) {
			delta[i] += val;
			return;
		}
		prop(i);
		increment_main(2 * i, a, b, val);
		increment_main(2 * i + 1, a, b, val);
		update(i);
	}

	int minimum_main(int i, int a, int b) {
		if (b < lo[i] || hi[i] < a) return INT_MAX;
		if (a <= lo[i] && hi[i] <= b) return minim[i] + delta[i];
		prop(i);
		int L = minimum_main(2 * i, a, b);
		int R = minimum_main(2 * i + 1, a, b);
		update(i);
		return min(L, R);
	}

	void increment(int a, int b, int val) {
		increment_main(1, a, b, val);
	}
	
	int minimum(int a, int b) {
		return minimum_main(1, a, b);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	segTree st;
	st.init(n);	
	ar = vector<int>(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		st.increment(i + 1, i + 1, ar[i]);
	}
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int a, b;
			cin >> a >> b;
			cout << st.minimum(a, b) << '\n';
		} else if (c == 2) {
			int a, b, val;
			cin >> a >> b >> val;
			st.increment(a, b, val);
		}
	}
}
