/**
 *  author: MKutayBozkurt
 *  created: 29.11.2020 10:05:21
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m, r, c; cin >> n >> m >> r >> c;
    int ans = r - 1 + c - 1;
    ans = max(ans, n - r + m - c);
    ans = max(ans, abs(r - 1) + abs(c - m));
    ans = max(ans, abs(r - n) + abs(c - 1));
    cout << ans << '\n';
  }
}
