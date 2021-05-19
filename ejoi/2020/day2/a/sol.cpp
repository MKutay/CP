#include <bits/stdc++.h>
using namespace std;
 
bool is_sorted(vector<int> a) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) return 0;
	}
	return 1;
}
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s; cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<pair<int, int>> ans, ans2;
	auto b = a;
	int k = 0;
	while (!is_sorted(a) && k < 30000) {
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int c = a[i] ^ a[i + 1];
				if (c < a[i + 1]) {
					a[i] = c;
					ans.emplace_back(i, i + 1);
				}
				else {
					a[i + 1] = c;
					ans.emplace_back(i + 1, i);
				}
			}
		}
		k++;
	}
	if (k < 30000 - 2) {
		cout << ans.size() << '\n';
		for (auto p : ans) {
			cout << p.first + 1 << " " << p.second + 1 << '\n';
		}
		return 0;
	}
	a = b;
	k = 0;
	while (!is_sorted(a) && k < 30000) {
		reverse(a.begin(), a.end());
		for (int i = 0; i < n - 1; i++) {
			if (a[i] > a[i + 1]) {
				int c = a[i] ^ a[i + 1];
				if (c < a[i + 1]) {
					a[i] = c;
					ans.emplace_back(i, i + 1);
				}
				else {
					a[i + 1] = c;
					ans.emplace_back(i + 1, i);
				}
			}
		}
		k++;
	}
	if (k < 30000 - 2) {
		cout << ans.size() << '\n';
		for (auto p : ans) {
			cout << p.first + 1 << " " << p.second + 1 << '\n';
		}
	}
	assert(false);
	//for (int x : a) cout << x << " ";
	//cout << '\n';
}