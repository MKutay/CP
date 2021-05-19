#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

void solve() {
	int p, f; cin >> p >> f;
	vector<int> cnt(2); cin >> cnt;
	int s, w; cin >> s >> w;
	int sum = p + f;
	long long ans = 0;
	if (s < w) {
		ans += 
	} else {

	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}

