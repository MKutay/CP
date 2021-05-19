/**
 *  author: MKutayBozkurt
 *  created: 22.01.2021 20:27:36
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
  }
}
