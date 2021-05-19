#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, p, q; cin >> n >> p >> q;
	vector<int> a(n); cin >> a;
	sort(a.begin(), a.end());
	vector<int> diff(n - 1);
	for (int i = 0; i < n - 1; i++) {
		diff[i] = a[i + 1] - a[i];
	}
	
	return 0;
}
