// https://www.youtube.com/watch?v=kPaJfAUwViY

#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;

struct fenwicktree {
	vector<int> table;
	void init(int size) {
		table = vector<int>(size);
	}

	void update(int i, int delta) {
		while (i < n + 1) {
			table[i] += delta;
			i += i & -i;
		}
	}

	int sum(int i) {
		int s = 0;
		while (i > 0) {
			s += table[i];
			i -= i & -i;
		}
		return s;
	}

	int rangeSum(int i, int j) {
		return sum(j) - sum(i);		
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	fenwicktree ft;
	ft.init(n + 1);
	a = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += ft.rangeSum(a[i], n);
		ft.update(a[i], 1);
	}
	cout << ans << '\n';
	return 0;
}
