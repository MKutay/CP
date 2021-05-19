#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> sag(10005), sol(10005);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		sag[a]++;
		sol[b]++;
	}
	long long ans = 0;
	for (int i = 1; i <= 10000; i++) {
		ans += abs(sag[i] - sol[i]);
	}
	cout << ans << '\n';
	return 0;

}

