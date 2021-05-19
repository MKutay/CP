#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

void solve() {
	string s; cin >> s;
	int x; cin >> x;
	int n = s.size();
	string ans;
	for (int i = x; i < n; i++) {
		ans += s[i];
	}
	int d = (n & 1 ? n / 2 - 1 : n / 2);
	for (int i = d; i < min(d + x, n); i++) {
		ans += s[i];
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}

