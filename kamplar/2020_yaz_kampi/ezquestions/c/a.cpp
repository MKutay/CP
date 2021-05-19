#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int ans = 0, k = -1;
    for (int i = 0; i < n; i++) {
      if (a[i].second >= k) {
        k = a[i].first;
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
