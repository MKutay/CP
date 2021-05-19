/**
 *  author: MKutayBozkurt
 *  created: 19.01.2021 17:35:35
**/
#include <bits/stdc++.h>
using namespace std;

int isp(int a) {
  if (a == 1) return 0;
  if (a == 2) return 1;
  int n = sqrt(a) + 1;
  for (int i = 2; i <= n; i++) {
    if (a % i == 0) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int D; cin >> D;
    int a = 1 + D, b;
    for (int i = a; ; i++) {
      if (i % 2 == 0 && i != 2) continue;
      if (isp(i)) {
        b = i;
        break;
      }
    }
    int c = b + D, d;
    for (int i = c; ; i++) {
      if (i % 2 == 0 && i != 2) continue;
      if (isp(i)) {
        d = i;
        break;
      }
    }
    if (D + d > b * d) assert(false);
    cout << b * d << '\n';
  }
}
