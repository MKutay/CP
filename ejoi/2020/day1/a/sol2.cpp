#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<pair<int, int>> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second; // first = cap, second = litre
	}
	a[n] = {LLONG_MAX, LLONG_MAX};
	while (q--) {
		int x, y; cin >> x >> y, x--;
		int mx = -1;
		for (int i = x; i <= n; i++) {
			if (i == n) {
				cout << 0 << '\n';
				break;
			}
			if (a[i].first > mx) {
				mx = a[i].first;
				y -= a[i].second;
			}
			if (y <= 0) {
				cout << i + 1 << '\n';
				break;
			}
	 	}
  }
}