#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int ans = 0;
    while (n > 1) {
      if (n & 1) {
        n--;
      } else {
        if (n == 2) {
          n /= 2;
          ans++;
          continue;
        }
        int d = n / 2;
        n /= d;
      }
      ans++;
    }
    cout << ans << '\n';
  }
}
