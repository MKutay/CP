/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 13:28:54
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, C; cin >> N >> C;
  vector<pair<int, int>> e;
  for (int i = 0; i < N; i++) {
    int a, b, c; cin >> a >> b >> c;
    e.emplace_back(a - 1, c);
    e.emplace_back(b, -c);
  }
  sort(e.begin(), e.end());
  int ans = 0, fee = 0, t = 0;
  for (auto [x, y] : e) {
    if (x != t) {
      ans += min(C, fee) * (x - t);
      t = x;
    }
    fee += y;
  }
  cout << ans << '\n';
}
