/**
 *  author: MKutayBozkurt
 *  created: 17.01.2021 21:42:09
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int X, Y; cin >> Y >> X;
    int z = max(X, Y);
    int z2 = (z - 1) * (z - 1), ans = 0;
    if (z & 1) {
      if (Y == z) {
        ans = z2 + X;
      } else {
        ans = z2 + 2 * z - Y;
      }
    } else {
      if (X == z) {
        ans = z2 + Y;
      } else {
        ans = z2 + 2 * z - X;
      }
    }
    cout << ans << '\n';
  }
}
