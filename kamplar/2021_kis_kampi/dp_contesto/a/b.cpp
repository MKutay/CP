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
  vector<vector<int>> dp(N + 1, vector<int>(2, -inf));
  function<int(int, int)> f = [&](int i, bool b) {
    if (i > N) return -inf;
    if (dp[i][b] != -inf && i != 1) return dp[i][b];
    if (b == 1) {
      return dp[i][b] += f(i + 1, 0) + f(i + 2, 1);
    } else {
      return dp[i][b] += f(i + 1, b) + f(i + 2, b);
    }
  };
  dp[1][0] = 1;
  f(1, 0);
  cout << dp[N][0] << '\n';
}
