#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	int ans = 1e9;
	for (int i = 0; i <= n - m; i++) {
		int res = 0;
		string ss, tt;
		for (int j = i; j < i + m; j++) {
			if (s[j] != t[j - i]) res++;
			tt += t[j - i];
			ss += s[j];
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
}
