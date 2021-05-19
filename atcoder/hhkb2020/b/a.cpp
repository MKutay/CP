#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i < n - 1 && a[i][j] == a[i + 1][j] && a[i][j] == '.') ans++;
      if (j < m - 1 && a[i][j] == a[i][j + 1] && a[i][j] == '.') ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}
