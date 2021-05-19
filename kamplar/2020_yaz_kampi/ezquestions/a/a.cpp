#include <bits/stdc++.h>
using namespace std;

int fpow(int a, int b) {
	if (b == 0) return 1;
	int res = fpow(a, b / 2);
	res *= res;
	if (b & 1) res *= a;
	return res % 10;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		cout << fpow(a % 10, b) % 10 << '\n';
	}
}
