#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n * k); for (int &x : a) cin >> x;
  long long ans = 0;
  int m = ceil(n / 2.0);
  m = n - m;
  int b = 0;
  for (int i = n * k - m - 1; i >= 0; i -= m + 1) {
    if (b == k) break;
    ans += a[i];
    b++;
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
