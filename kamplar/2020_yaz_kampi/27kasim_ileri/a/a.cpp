/**
 *  https://codeforces.com/contest/1188/problem/C
 *  author: MKutayBozkurt
 *  created: 27.11.2020 17:05:07
**/
#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int N, K;
int m;
vector<int> A;

int add(int x, int y) {
  x += y;
  if (x >= mod) return x - mod;
  return x;
}

int solve(int d) {
  vector<vector<int>> dp(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    dp[1][i] = i;
  }
  for (int i = 1; i < K; i++) {
    int p = 0;
    for (int j = 0; j < N; j++) {
      while (A[j] - A[p] >= d) p++;
      dp[i + 1][j + 1] = add(dp[i + 1][j], dp[i][p]);
    }
  }
  return dp[K][N];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> K;
  A = vector<int>(N);
  for (int &x : A) cin >> x;
  sort(A.begin(), A.end());
  m = A[N - 1] - A[0];
  long long ans = 0;
  for (int i = 1; i * (K - 1) <= m; i++) {
    ans = add(ans, solve(i));
  }
  cout << ans << '\n';
}
