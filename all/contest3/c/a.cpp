#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, pair<T, T> &p) {
	return is >> p.first >> p.second;
}

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int main() {
	//Particles
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	srand(time(0));
	int n, l, k; cin >> n >> l >> k;
	vector<pair<int, int>> a(n), b(n); cin >> a >> b;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> aa, bb;
	for (int i = 0; i < n; i++) {
		aa.push({a[i].first + ceil(l / (double) a[i].second), i});
		bb.push({b[i].first + ceil(l / (double) b[i].second), i});
	}
	while (k--) {
		cout << aa.top().second + 1 << " " << bb.top().second + 1 << '\n';
		aa.pop();
		bb.pop();
	}
	return 0;
}

