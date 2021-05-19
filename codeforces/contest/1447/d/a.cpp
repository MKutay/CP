#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  string a, b; cin >> a >> b;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) - 1;
      dp[i][j] = max(0, dp[i][j]);
      if (a[i] == b[j]) {
        dp[i][j] = dp[i + 1][j + 1] + 2;
      }
      ans = max(ans, dp[i][j]);
    }
  }
  cout << ans << '\n';
}
