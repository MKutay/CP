/**
 *  author: MKutayBozkurt
 *  created: 22.01.2021 19:50:42
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    x2 -= x1;
    y2 -= y1;
    x3 -= x1;
    y3 -= y1;
    long long cross_product = (long long) x2 * y3 - (long long) x3 * y2;
    if (cross_product < 0) {
      // P2 on the left from P3;
      cout << "RIGHT\n";
    } else if (cross_product > 0) {
      cout << "LEFT\n";
    } else {
      cout << "TOUCH\n";
    }
  }
}
