/**
 *  author: kutay
 *  created: 29.03.2021 17:36:01
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    for (int i = N; ; i++) {
      int x = i;
      int s = 0;
      while (x > 0) {
        s += x % 10;
        x /= 10;
      }
      if (gcd(i, s) > 1) {
        cout << i << '\n';
        break;
      }
    }
  }
}
