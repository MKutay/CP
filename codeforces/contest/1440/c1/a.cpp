#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      a[i][j] = c - '0';
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < m - 2; j++) {
      int s = 0;
      for (int l = i; l < i + 2; l++) {
        for (int r = j; r < j + 2; r++) {
          s += a[l][r];
        }
      }
      if (s == 3) {
        for (int l = i; l < i + 2; l++) {
          for (int r = j; r < j + 2; r++) {
            if (a[l][r]) {
              ans.emplace_back(l, r);
            }
          }
        }
      }
    }
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size() - 3; i += 3) {
    for (int j = i; j < i + 3; j++) {
      cout << ans[j].first + 1 << " " << ans[j].second + 1 << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
