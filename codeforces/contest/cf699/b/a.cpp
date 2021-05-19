/**
 *  author: MKutayBozkurt
 *  created: 07.02.2021 13:01:39
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(N); for (int &x : A) cin >> x;
  int ans = INT_MIN;
  for (int a = 0; a < 10000; a++) {
    for (int i = 0; i < N; i++) {
      if (i == N - 1) {
        K--;
        ans = -1;
        break;
      }
      if (A[i + 1] > A[i]) {
        A[i]++;
        K--;
        ans = i + 1;
        break;
      }
    }
    if (K == 0) {
      cout << ans << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}
