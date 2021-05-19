/**
 *  author: MKutayBozkurt
 *  created: 29.11.2020 10:05:21
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, p, k; cin >> n >> p >> k;
  string s; cin >> s;
  int x, y; cin >> x >> y;
  p--;
  vector<int> b(k);
  int ans = INT_MAX;
  for (int i = n - 1; i >= p; i--) {
    int t = (i - p) * y;
    b[i % k] += (s[i] == '0');
    ans = min(ans, t + b[i % k] * x);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
