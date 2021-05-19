/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N); for (int &x : A) cin >> x;
    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
      int mn = min(A[i], A[i + 1]);
      int mx = max(A[i], A[i + 1]);
      if (mn * 2 < mx) {
        while (mx > mn * 2) {
          mx = ceil(mx / 2.0);
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
