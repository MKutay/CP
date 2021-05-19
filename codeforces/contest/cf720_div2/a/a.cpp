/**
 *  author: MKutayBozkurt
 *  created: 07.05.2021 17:49:58
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int A, B; cin >> A >> B;
    int z = A * (B + 10);
    int b = B / 2 + 4;
    int x = A * b;
    int y = A * (B + 10 - b);
    if (z % A * B == 0 && x % A == 0 && y % A == 0 && x != 0 && y != 0 && z != 0) {
      cout << "YES\n";
      cout << x << " " << y << " " << z << '\n';
    } else {
      cout << "NO\n";
    }
  }
}
