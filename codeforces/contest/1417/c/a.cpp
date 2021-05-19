#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++) {
      a[i]--;
      v[a[i]].emplace_back(i);
    }
    vector<int> ans(n + 1, -1);
    int nxt = n;
    for (int i = 0; i < n; i++) {
      int d = -1;
      int p = -1;
      v[i].emplace_back(n);
      for (int pos : v[i]) {
        d = max(d, pos - p);
        p = pos;
      }
      while (d <= nxt && nxt >= 1) {
        ans[nxt] = i + 1;
        nxt--;
      }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
  }
}
