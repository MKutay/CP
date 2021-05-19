#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<vector<int>> rmq(23, vector<int>(500000));

int f(int l, int r) {
	int sz = 32 - __builtin_clz(r - l + 1);
	return min(rmq[sz][l], rmq[sz][r - (1 << sz) + 1]);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> rmq[0][i];
	}
	for (int i = 1; i < 23; i++) {
		for (int j = 1; j + (1 << n) - 1 <= n; j++) {
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + (1 << i)]);
		}
	}
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << f(l, r) << '\n';
	}
	return 0;
}
