#include <bits/stdc++.h>
using namespace std;
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<int> ind;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[0]) ind.push_back(i);
	}
	vector<int> vis(n);
	int ans = 0;
	for (int x : ind) {
		for (int i = x; i >= 0; i--) {
			if (a[i] > b[0] || vis[i]) break;
			vis[i] = 1;
			ans++;
		}
		for (int i = x + 1; i < n; i++) {
			if (a[i] > b[0] || vis[i]) break;
			vis[i] = 1;
			ans++;
		}
	}
	if (ans > n) assert(0);
	cout << ans << '\n';
}