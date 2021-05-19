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
	vector<int> a(n); cin >> a;
	int mx = *max_element(a.begin(), a.end());
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int g = mx - a[0];
	for (int i = 1; i < n; i++) {
		g = gcd(g, mx - a[i]);
	}
	long long ans = (mx * 1ll * n - sum) / g;
	cout << ans << " " << g << '\n';
}
