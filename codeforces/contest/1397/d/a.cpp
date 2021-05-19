#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n); cin >> a;
	int mx = *max_element(a.begin(), a.end());
	int sum = accumulate(a.begin(), a.end(), 0);

	if (mx * 2 > sum || (sum & 1)) cout << "T\n";
	else cout << "HL\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
