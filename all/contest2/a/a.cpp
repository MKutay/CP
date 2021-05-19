#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> a(n); cin >> a;
	vector<int> p(n - 1);
	for (int i = 0; i < n - 1; i++) {
		p[i] = a[i + 1] - a[i];
	}
	sort(p.begin(), p.end());
	// 2 3
	// 1 4
	// 2 3
	// 1 2 5 8 10 k = 2 ans = 8?
	// 1 2 3 3
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i >= n - k) ans++;
		else ans += p[i];
	}
	cout << ans << '\n';
	return 0;
}
