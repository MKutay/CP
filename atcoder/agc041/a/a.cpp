#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, a, b; cin >> n >> a >> b;
	if (a > b) swap(a, b);
	if (a % 2 == b % 2) {
		cout << (b - a) / 2 << '\n';
		return 0;
	}
	cout << min((n - b) + 1 + (n - a), (a - 1) + 1 + (b - 1)) / 2 << '\n';
}
