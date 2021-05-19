#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<string> a(n); for (string &x : a) cin >> x;
    sort(a.begin(), a.end());
    string p = "sadasdasd";
    bool flag = 1;
    for (int i = 0; i < n; i++) {
      if (p == a[i].substr(0, p.size())) {
        flag = 0;
        break;
      }
      p = a[i];
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
  }
}
