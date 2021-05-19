#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n); for (int &x : a) cin >> x;
    for (int i = 0; i < min(k, 100ll); i++) {
      for (int j = 0; j < n; j++) {
        if (j == 0) {
          a[j] = a[j] & a[j + 1];
        } else if (j == n - 1) {
          a[j] = a[j] & a[j - 1];
        } else {
          a[j] = (a[j] & a[j - 1]) & a[j + 1];
        }
      }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << '\n';
  }
}
