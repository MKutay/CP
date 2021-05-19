#include <bits/stdc++.h>
using namespace std;

template<typename T, typename Q>
istream &operator>>(istream &is, pair<T, Q> &p) {
	return is >> p.first >> p.second;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

template<typename T, typename Q>
ostream &operator<<(ostream &os, pair<T, Q> p) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template<typename T>
ostream &operator<<(ostream &os, vector<T> v) {
	os << "[";
	for (auto it = v.begin(); it != v.end(); it++) 
		os << (it == v.begin() ? "" : ", ") << *it;
	return os << "]";
}

template<typename T, typename Q>
ostream &operator<<(ostream &os, map<T, Q> m) {
	os << "[";
	for (auto it = m.begin(); it != m.end(); it++) 
		os << (it == m.begin() ? "" : ", ") << *it;
	return os << "]";
}
#define imie(...) " [" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "

void solve() {
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	vector<long long> mn(6), mx(6);
	mn[0] = mx[0] = 1;
	for (int i = 1; i <= 5; i++) {
		mx[i] = -1e18;
		mn[i] = 1e18;
	}
	for (int x : a) {
		for (int j = 5; j > 0; j--) {
			if (x >= 0) {
				if (mx[j - 1] != -1e18)
					mx[j] = max(mx[j], mx[j - 1] * x);
				if (mn[j - 1] != 1e18)
					mn[j] = min(mn[j], mn[j - 1] * x);
			} else {
				if (mn[j - 1] != 1e18)
					mx[j] = max(mx[j], mn[j - 1] * x);
				if (mx[j - 1] != -1e18)
					mn[j] = min(mn[j], mx[j - 1] * x);
			}
		}
	}
	cout << mx[5] << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
