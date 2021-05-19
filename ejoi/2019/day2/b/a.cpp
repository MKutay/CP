#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int m, n; cin >> m >> n;
	vector<int> a(m + n - 1), b(m + n - 1); cin >> a >> b;
}
