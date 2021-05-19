#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("knapsack2.gir", "r", stdin);
  freopen("knapsack2.cik", "w", stdout);
  int N, X; cin >> N >> X;
  vector<int> A(N); for (int &x : A) cin >> x;
  vector<vector<int>> dp(N + 1, vector<int>(X + 1, -1e9));

  function<int(int, int)> f = [&](int i, int x) {
    if (x == 0) return 0;
    if (x < 0 || i == N) return (int) 1e9;
    if (dp[i][x] != -1e9) return dp[i][x];

    return dp[i][x] = min(f(i + 1, x), f(i + 1, x - A[i]) + 1);
  };

  int ans = f(0, X);
  cout << (ans == 1e9 ? 0 : ans) << '\n';
}
