#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	for (int i = 0; i < 20; i++) {
		string t;
		cin >> t;
		s += t;
	}
	long long ans = 0;
	for (int i = 0; i < s.size(); i++) {
		long long sum = 1;
		for (int j = i; j < i + 13; j++) {
			sum *= s[j] - '0';
		}
		ans = max(ans, sum);		
	}
	cout << ans << '\n';
	return 0;
}