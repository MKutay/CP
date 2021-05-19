/**
 *  author: MKutayBozkurt
 *  created: 22.01.2021 19:50:42
**/
#include <bits/stdc++.h>
using namespace std;


// Cross Product template
struct P {
  int x, y;
  void read() {
    cin >> x >> y;
  }
  P operator -(const P &b) const {
    return P{x - b.x, y - b.y};
  }
  void operator -=(const P &b) {
    x -= b.x;
    y -= b.y;
  }
  long long operator *(const P &b) const {
    return (long long) x * b.y - (long long) y * b.x;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    P p1, p2, p3;
    p1.read();
    p2.read();
    p3.read();
    p3 -= p1;
    p2 -= p1;
    long long cross_product = p2 * p3;
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

