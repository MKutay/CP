#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cur = 0;
    int last = -1;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        if (last != -1 && last == i - 1) {
          cur += 2;
        } else {
          cur += 1;
        }

        if (last != -1 && last != i - 1) {
          a[i - last - 1]++;
        }
        last = i;
      }
    }
    if (last == -1) {
      cout << max(0, 2 * k - 1) << '\n';
      continue;
    }
    cur += 2 * k;
    int rem = k;
    for (int i = 1; i <= n; i++) {
      while (rem >= i && a[i]) {
        a[i]--;
        rem -= i;
        cur++;
      }
    }
    cout << min(cur, 2 * n - 1) << '\n';
  }
}
