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
	vector<long long> a(n); cin >> a;
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			cout << "1 1\n";
			cout << -a[0] << '\n';
			a[0] = 0;
		}
		return 0;
	}
	cout << "1 " << n << '\n';
	for (int i = 0; i < n - 1; i++) cout << -a[i] * n << " "; cout << "0\n";
	cout << "1 " << n - 1 << '\n';
	for (int i = 0; i < n - 1; i++) cout << a[i] * (n - 1) << " " << '\n';
	cout << n << " " << n << '\n';
	cout << -a[n - 1] << '\n';
}
