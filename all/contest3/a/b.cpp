#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
	for (auto &x : v) is >> x;
	return is;
}

int con(char c) {
	if (c >= 'a') return c - 'a';
	return c - 'A' + 26;
}

const int mod = 1e9 + 7;

int main() {
	// Magic
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	return 0;
}
