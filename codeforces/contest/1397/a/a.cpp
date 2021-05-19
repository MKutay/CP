#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

void solve() {
	int n; cin >> n;
	vector<string> a(n); cin >> a;
	map<char, int> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int) a[i].size(); j++) {
			m[a[i][j]]++;
		}
	}
	bool flag = 1;
	for (auto p : m) {
		flag &= p.second % n == 0;
	}
	puts(flag ? "YES" : "NO");
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
