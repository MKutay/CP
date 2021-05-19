#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	sort(a.begin(), a.end());
	if (a[0] == a[n - 1]) cout << n << '\n';
	else cout << "1" << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
