#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("knapsack1.gir", "r", stdin);
  freopen("knapsack1.cik", "w", stdout);
  int N, X; cin >> N >> X;
  vector<int> A(N); for (int &x : A) cin >> x;
  vector<vector<int>> dp(N + 1, vector<int>(X + 1, -1e9));

  function<int(int, int)> f = [&](int i, int x) {
    if (x == 0) return dp[i][x] = 1;
    if (x < 0 || i == N) return 0;
    if (dp[i][x] != -1e9) return dp[i][x];

    return dp[i][x] = max(f(i + 1, x), f(i + 1, x - A[i]));
  };

  cout << f(0, X) << '\n';
}
