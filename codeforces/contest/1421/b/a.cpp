#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
      }
    }
    vector<pair<int, int>> ans;
    {
      if (a[0][1] == '0') {
        ans.emplace_back(0, 1);
      }
      if (a[1][0] == '0') {
        ans.emplace_back(1, 0);
      }
      if (a[n - 1][n - 2] == '1') {
        ans.emplace_back(n - 1, n - 2);
      }
      if (a[n - 2][n - 1] == '1') {
        ans.emplace_back(n - 2, n - 1);
      }
    }
    if (ans.size() > 2) {
      ans.clear();
      if (a[0][1] == '1') {
        ans.emplace_back(0, 1);
      }
      if (a[1][0] == '1') {
        ans.emplace_back(1, 0);
      }
      if (a[n - 1][n - 2] == '0') {
        ans.emplace_back(n - 1, n - 2);
      }
      if (a[n - 2][n - 1] == '0') {
        ans.emplace_back(n - 2, n - 1);
      }
    }
    cout << ans.size() << '\n';
    for (auto x : ans) {
      cout << x.first + 1 << " " << x.second + 1 << '\n';
    }
  }
}
