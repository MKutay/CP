#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
	cin >> n;
  vector<long long> a(n);

  int c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c = max(0ll, c + a[i] - 1);
  }

  for (int i = 0; ; i++) {
    if (c == 0) {
      rotate(a.begin(), a.begin() + i, a.begin() + n);
      break;
    }
    c = max(0ll, c + a[i] - 1);
  }

	auto sumn2 = [&](long long v) {
		return v * (v + 1) * (2 * v + 1) / 6;
	};

  long long result = 0;
  for (int i = 0; i < n; i++) {
    result += sumn2(a[i] + c - 1) - sumn2(c - 1);
    c = max(0ll, c + a[i] - 1);
  }
  cout << result << endl;
}
