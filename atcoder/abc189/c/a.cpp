/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 15:00:13
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  long long ans = 0;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    int mn = 1e9;
    for (int j = i; j < N; j++) {
      mn = min(mn, A[j]);
      a[i][j] = mn * (j - i + 1);
      ans = max(ans, a[i][j]);
    }
  }
  cout << ans << '\n';
}
