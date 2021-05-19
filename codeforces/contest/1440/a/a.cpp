#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, c0, c1, h; cin >> n >> c0 >> c1 >> h;
  string s; cin >> s;
  long long ans = 0;
  if (c0 < c1) {
    if (h + c0 < c1) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '1') ans += h + c0;
        else ans += c0;
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans += c0;
        else ans += c1;
      }
    }
  } else {
    if (h + c1 < c0) {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans += h + c1;
        else ans += c1;
      }
    } else {
      for (int i = 0; i < n; i++) {
        if (s[i] == '0') ans += c0;
        else ans += c1;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
