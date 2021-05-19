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
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int zero = 0, one = 0;
	for (int i = 0; i < k; i++) {
		int tmp = -1;
		for (int j = i; j < n; j += k) {
			if (s[j] != '?') {
				if (tmp != -1 && s[j] - '0' != tmp) {
					cout << "NO\n";
					return;
				}
				tmp = s[j] - '0';
			}
		}
		if (tmp != -1) {
			(tmp == 0 ? zero : one)++;
		}
	}
	if (max(zero, one) > k / 2) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> a(n);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
