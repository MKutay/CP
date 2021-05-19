/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 15:00:13
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<string> A(N); for (auto &x : A) cin >> x;
  vector<int> dp(2, 1);
  for (int i = 0; i < N; i++) {
    vector<int> new_dp(2, 0);
    if (A[i] == "OR") {
      new_dp[1] = dp[1] * 2 + dp[0];
      new_dp[0] = dp[0];
    } else {
      new_dp[1] = dp[1];
      new_dp[0] = dp[1] + dp[0] * 2;
    }
    swap(dp, new_dp);
  }
  cout << dp[1] << '\n';
}
