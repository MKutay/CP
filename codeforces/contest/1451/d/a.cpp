#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int d, k; cin >> d >> k;
    int x = 0, y = 0;
    while (1) {
      if (x <= y && (x + k) * (x + k) + y * y <= d * d) {
        x += k;
      } else if (x > y && (y + k) * (y + k) + x * x <= d * d) {
        y += k;
      } else break;
    }
    if (x == y) cout << "Utkarsh\n";
    else cout << "Ashish\n";
  }
}
