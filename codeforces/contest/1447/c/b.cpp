#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n, w; cin >> n >> w;
  int W = w;
  w = 0;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    if (a[i].first >= ceil(W / 2.0) && a[i].first <= W) {
      cout << "1\n" << i + 1 << '\n';
      return;
    }
  }
  sort(a.begin(), a.end());
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i].first <= ceil(W / 2.0)) {
      w += a[i].first;
      ans.emplace_back(a[i].second);
    }
    if (w >= ceil(W / 2.0)) {
      cout << ans.size() << '\n';
      for (int x : ans) cout << x + 1 << " ";
      cout << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
}

