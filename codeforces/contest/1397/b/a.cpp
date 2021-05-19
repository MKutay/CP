#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}
#define int long long
const int inf = 1e17;

int mul(int a, int b) {
	return (a * b >= inf ? inf : a * b);
}

int add(int a, int b) {
	return (a + b >= inf ? inf : a + b);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	sort(a.begin(), a.end());
	if (n <= 2) {
		cout << a[0] - 1 << '\n';
		return 0;
	}
	int ans = accumulate(a.begin(), a.end(), 0ll) - n;
	for (int x = 1; ; x++) {
		int cur = 1, cost = 0;
		for (int i = 0; i < n; i++) {
			cost = add(cost, abs(a[i] - cur));
			cur = mul(cur, x);
		}
		if (cur == inf || cur / x > ans + a[n - 1]) break;
		ans = min(ans, cost);
	}
	cout << ans << '\n';
}
