#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	long long x = 0;
	long long s = 1;
	long long ans = 0;
	long long last = 0;
	while (x != n) {
		if (x < n) {
			if (last) {
				s = 1;
			}
			x += s;
			s *= 2;
			last = 0;
		} else {
			if (!last) {
				s = 1;
			}
			x -= s;
			s *= 2;
			last = 1;
		}
		ans++;
	}
	cout << ans << '\n';
	return 0;
}

