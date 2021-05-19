#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int mx = 200;

vector<vector<vector<int>>> dp(mx, vector<vector<int>>(mx, vector<int>(mx)));

int lcs(string s, string t, int i, int j, int k) {
  if (k == 0) return 0;
  if (i < 0 || j < 0) return INT_MIN;
  if (dp[i][j][k] != -2) return dp[i][j][k];
  if (s[i] == t[j]) return dp[i][j][k] = max(lcs(s, t, i - 1, j - 1, k), lcs(s, t, i - 1, j - 1, k - 1) + (int) s[i]);
  else return dp[i][j][k] = max(lcs(s, t, i - 1, j, k), lcs(s, t, i, j - 1, k));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    string s, t; cin >> s >> t;
    int K; cin >> K;
    for (int i = 0; i < mx; i++) {
      for (int j = 0; j < mx; j++) {
        for (int k = 0; k < mx; k++) {
          dp[i][j][k] = -2;
        }
      }
    }
    int ans = lcs(s, t, (int) s.size() - 1, (int) t.size() - 1, K);
    cout << (ans < 0 ? 0 : ans) << '\n';
  }
}
