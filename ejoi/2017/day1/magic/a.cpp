#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

#define int long long
const int mod = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	int n; cin >> n;
	string s; cin >> s;
	vector<int> a;
	map<char, int> m;
	m[s[0]] = 1;
	int j = 1, tmp = 0;
	for (int i = 0; i < n; i++) {
		if (m[s[i]] == 0) tmp += m[s[i]] = (-1 * (rand() % 999983) * j * j++);
		a.emplace_back(m[s[i]]);
	}
	vector<int> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + (a[i] == 1 ? -tmp : a[i]);
	}
	map<int, int> ans;
	int res = 0;
	for (auto it : pre) {
		res = (res + (ans[it]++) % mod) % mod;
	}
	cout << res << '\n';
	return 0;
}
// 
