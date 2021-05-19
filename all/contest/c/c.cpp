#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A, B, n, m;
	cin >> A >> B >> n >> m;
	vector<int> a(n + 1), b(m + 1);
	a[0] = 0;
	b[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	return 0;
}
