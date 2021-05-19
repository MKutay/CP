#include "bits/stdc++.h"
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += a[n - 1] - a[i];
    }
    if (a[0] < s) {
      cout << n - (s - a[0]) % n << '\n';
    } else {
      cout << s - a[0] << '\n';
    }
  }
}
