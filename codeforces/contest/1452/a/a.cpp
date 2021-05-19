#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int a, b; cin >> a >> b;
    if (abs(a - b) <= 1) {
      cout << a + b << '\n';
    } else {
      int mx = max(a, b);
      int mn = min(a, b);
      cout << (a + b) * 2 - 1 - (mn * 2) << '\n';
    }
  }
}
