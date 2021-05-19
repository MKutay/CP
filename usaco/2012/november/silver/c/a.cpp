/**
 *  author: MKutayBozkurt
 *  created: 02.03.2021 20:02:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("bbreeds.in", "r", stdin);
  freopen("bbreeds.out", "w", stdout);
  string S; cin >> S;
  int N = S.size();
  vector<int> pre(N + 1);
  vector<vector<int>> dp(N, vector<int>(N, -1));
  for (int i = 0; i < N; i++) {
    pre[i + 1] = pre[i] + (S[i] == '(' ? 1 : -1);
  }

  function<int(int ,int)> f = [&](int i, int a) {
    if (i == N) return 1;
    if (dp[i][a] >= 0) return dp[i][a];
    int b = pre[i] - a;
    if (S[i] == '(') return dp[i][a] = (f(i + 1, a + 1) + f(i + 1, a)) % 2012;
    else {
      int ans = 0;
      if (a > 0) ans += f(i + 1, a - 1);
      if (b > 0) ans += f(i + 1, a);
      return dp[i][a] = ans % 2012;
    }
  };

  cout << f(0, 0) << '\n';
}
