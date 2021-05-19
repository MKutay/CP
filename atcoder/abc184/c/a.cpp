#include <bits/stdc++.h>
using namespace std;

int f(int r1, int c1, int r2, int c2) {
  if (r1 + c1 == r2 + c2) {
    return 1;
  } else if (r1 - c1 == r2 - c2) {
    return 1;
  } else if (abs(r1 - r2) + abs(c1 - c2) <= 3) {
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
  if (r1 == r2 && c1 == c2) {
    cout << "0\n";
    return 0;
  }
  if (f(r1, c1, r2, c2)) {
    cout << "1\n";
    return 0;
  }

  if (abs(r1 + c1) % 2 == abs(r2 + c2) % 2) {
    cout << "2\n";
    return 0;
  }

  if (abs(abs(r2 - c2) - abs(r1 - c1)) <= 3) {
    cout << "2\n";
    return 0;
  }

  if (r1 == r2) {
    int x = abs(c1 - c2);
    if (x <= 5) {
      cout << "2\n";
      return 0;
    }
  }

  if (c1 == c2) {
    int x = abs(r1 - r2);
    if (x <= 5) {
      cout << "2\n";
      return 0;
    }
  }

  cout << "3\n";
}
