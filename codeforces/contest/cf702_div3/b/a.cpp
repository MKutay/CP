/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:16
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N); for (int &x : A) cin >> x;
    vector<int> c(3);
    for (int i = 0; i < N; i++) {
      c[A[i] % 3]++;
    }
    int C = N / 3;
    long long ans = 0;
    for (int i = 0; i < 10; i++) {
      for (int d = 0; d < 3; d++) {
        if (c[d] > C) {
          ans += c[d] - C;
          c[(d + 1) % 3] += c[d] - C;
          c[d] = C;
        }
      }
    }
    cout << ans << '\n';
  }
}
