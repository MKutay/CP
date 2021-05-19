#include "bits/stdc++.h"
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  int s = accumulate(a.begin(), a.end(), 0ll);
  int mx = *max_element(a.begin(), a.end());
  int l = s % (n - 1);
  if (l == 0) {
    l = n - 1;
  }
  cout << max(n - 1 - l, mx * (n - 1) - s) << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
