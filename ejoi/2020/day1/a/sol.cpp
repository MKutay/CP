#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<pair<int, int>> a(n + 1);
	vector<int> pre(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second; // first = cap, second = litre
		pre[i] = (i == 0 ? a[i].second : pre[i - 1] + a[i].second);
	}
	pre[n] = LLONG_MAX;
	a[n] = {LLONG_MAX, LLONG_MAX};
	while (q--) {
		int x, y; cin >> x >> y, x--;
		int val = y + (x == 0 ? 0 : pre[x - 1]);
		int ind = upper_bound(pre.begin(), pre.end(), val) - pre.begin();
		int ans;
		if (pre[ind - 1] == val) {
			ans = ind;
		} else {
			ans = ind + 1;
		}
		cout << (ans == n + 1 ? 0 : ans) << '\n';
  }
}