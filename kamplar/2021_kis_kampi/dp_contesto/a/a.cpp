/**
 *  author: MKutayBozkurt
 *  created: 07.04.2021 14:30:39
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int inf = 1e18;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> dp(N + 1, vector<int>(4ll, -inf));

  function<int(int, int)> f = [&](int i, int b) {
    if (i <= 0) return 0ll;
    if (dp[i][b] != -inf) return dp[i][b];
    if (b == 0) {
      return dp[i][b] = f(i - 1, b) + 1;
    } else if (b == 1) {
      return dp[i][b] = f(i - 1, 0) + f(i - 2, b);
    } else if (b == 2) {
      return dp[i][b] = f(i - 1, 0) + f(i - 2, b);
    } else {
      return dp[i][b] = f(i, 0) + f(i - 1, 3);
    }
  };

  dp[1][0] = 1;

  f(N, 0);

  cout << dp[N][3] << '\n';
}
