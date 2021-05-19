#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    while (q--) {
      int l, r; cin >> l >> r, l--, r--;
      string f;
      for (int i = l; i <= r; i++) f += s[i];
      int k = 0;
      vector<int> ind;
      for (int i = 0; i < n; i++) {
        if (s[i] == f[k]) {
          ind.emplace_back(i);
          k++;
        }
      }
      bool flag = 0;
      for (int i = 0; i < (int) ind.size() - 1; i++) {
        if (ind[i] + 1 < ind[i + 1]) {
          cout << "YES\n";
          flag = 1;
          break;
        }
      }
      if (flag) continue;
      for (int i = ind[0] - 1; i >= 0; i--) {
        if (s[i] == s[ind[0]]) {
          cout << "YES\n";
          flag = 1;
          break;
        }
      }
      if (flag) continue;
      for (int i = ind.back() + 1; i < n; i++) {
        if (s[i] == s[ind.back()]) {
          cout << "YES\n";
          flag = 1;
          break;
        }
      }
      if (flag) continue;
      cout << "NO\n";
    }
  }
}
