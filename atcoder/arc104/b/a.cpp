#include "bits/stdc++.h"
using namespace std;

#define int long long

int ways(int n, int k) {
  return min(k - 1, 2 * n + 1 - k);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k; cin >> n >> k;
  if (k < 0) k *= -1;
  int ans = 0;
  for (int i = 2; i <= 2 * n; i++) {
    if (i - k < 2) continue;
    ans += ways(n, i) * ways(n, i - k);
  }
  cout << ans << '\n';
}
