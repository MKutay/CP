#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    map<int, int> m;
    vector<int> a(n); for (int &x : a) cin >> x, m[x]++;
    bool f = 0;
    for (auto p : m) {
      if (p.second >= 2) {
        f = 1;
        break;
      }
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
  }
}
