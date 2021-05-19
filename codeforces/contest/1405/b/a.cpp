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
	long long ans = 1e18, sum = 0;
	for (int x : a) {
		sum += x;
		ans = min(ans, sum);
	}
	cout << max(0ll, -ans) << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
