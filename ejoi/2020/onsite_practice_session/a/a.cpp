#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string x, y; cin >> x >> y;
	if (x[0] == '-' || y[0] == '-') {
		long long a = stoll(x), b = stoll(y);
		cout << a + b << '\n';
		return 0;
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	if (x.size() > y.size()) {
		swap(x, y);
	}
	vector<int> a(y.size()), b(y.size());
	for (int i = 0; i < x.size(); i++) {
		a[i] = x[i] - '0';
	}
	for (int i = x.size(); i < y.size(); i++) {
		a[i] = 0;
	}
	for (int i = 0; i < y.size(); i++) {
		b[i] = y[i] - '0';
	}
	vector<int> ans;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] + b[i] <= 9) {
			ans.emplace_back(a[i] + b[i]);
		} else {
			ans.emplace_back(a[i] + b[i] - 10);
			if (i + 1 == a.size()) {
				ans.emplace_back(1);
			} else {
				b[i + 1]++;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for (int u : ans) cout << u;
	cout << '\n';
}

