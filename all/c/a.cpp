#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, v, p; cin >> n >> m >> v >> p;
	vector<int> a(n); cin >> a;
	sort(a.rbegin(), a.rend());
	int l = p, r = n;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (i < p - 1 || i >= mid - 1) {
				sum += m;
			} else {
				if (a[i] > a[mid - 1] + m) {
					sum = -1;
					break;
				}
				sum += (a[mid - 1] + m) - a[i];
			}
		}
		if (sum >= (long long) m * v) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << l << '\n';
	return 0;        
}
