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
  auto b = a;
  vector<pair<int, int>> ans, ans2;
  for (int i = 0; i <= n - 2; i += 2) {
    for (int j = 0; j <= m - 2; j += 2) {
      ans2.clear();
      int s = 0;
      for (int l = i; l < i + 2; l++) {
        for (int r = j; r < j + 2; r++) {
          s += a[l][r];
        }
      }
      if (s == 0) continue;
      else if (s == 1) {
        if (a[i][j]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i + 1][j]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i + 1][j + 1]) {
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i +1 , j);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 2) {
        if (a[i][j] && a[i + 1][j]) {
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j + 1] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i + 1, j);
        } else if (a[i][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i + 1][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 3) {
        if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j] && a[i + 1][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j] && a[i][j + 1] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 4) {
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j + 1);
      }
      for (int l = 0; l < ans2.size(); l++) {
        int x = ans2[l].first, y = ans2[l].second;
        a[x][y] ^= 1;
        ans.emplace_back(x, y);
      }
    }
  }
  for (int i = max(0, n - 4); i <= n - 2; i++) {
    for (int j = max(0, m - 4); j <= m - 2; j++) {
      int s = 0;
      for (int l = i; l < i + 2; l++) {
        for (int r = j; r < j + 2; r++) {
          s += a[l][r];
        }
      }
      if (s == 0) continue;
      else if (s == 1) {
        if (a[i][j]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i + 1][j]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i + 1][j + 1]) {
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i +1 , j);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 2) {
        if (a[i][j] && a[i + 1][j]) {
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j + 1] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i + 1, j);
        } else if (a[i][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i + 1][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 3) {
        if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j] && a[i + 1][j] && a[i][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i, j + 1);
        } else if (a[i][j + 1] && a[i + 1][j] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j);
          ans2.emplace_back(i + 1, j + 1);
        } else if (a[i][j] && a[i][j + 1] && a[i + 1][j + 1]) {
          ans2.emplace_back(i, j);
          ans2.emplace_back(i, j + 1);
          ans2.emplace_back(i + 1, j + 1);
        }
      } else if (s == 4) {
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j + 1);
        ans2.emplace_back(i + 1, j);
        ans2.emplace_back(i + 1, j + 1);
        ans2.emplace_back(i, j + 1);
      }
      for (int l = 0; l < ans2.size(); l++) {
        int x = ans2[l].first, y = ans2[l].second;
        a[x][y] ^= 1;
        ans.emplace_back(x, y);
      }
    }
  }
  cout << ans.size() / 3 << '\n';
  for (int i = 0; i <= (int) ans.size() - 3; i += 3) {
    for (int j = i; j < i + 3; j++) {
      cout << ans[j].first + 1 << " " << ans[j].second + 1 << ' ';
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
