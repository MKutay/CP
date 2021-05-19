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
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += 1 / (double) i;
	}
	cout << setprecision(100) << ans << '\n';
	return 0;
}
