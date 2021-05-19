#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<array<int, 3>> a(n + 1);
	a[0][0] = 0;
	a[0][1] = 0;
	a[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 1; i <= n; i++) {
		int t = a[i][0] - a[i - 1][0];
		int d = abs(a[i][1] - a[i - 1][1]) + abs(a[i][2] - a[i - 1][2]);
		if (!(d <= t && t % 2 == d % 2)) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}

