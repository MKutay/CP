#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("ikiliarama.gir", "r", stdin);
  freopen("ikiliarama.cik", "w", stdout);
  int n; cin >> n;
  set<int> s;
  while (n--) {
    int op; cin >> op;
    int x; cin >> x;
    if (op == 1) {
      auto it = s.find(x);
      if (it == s.end()) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
      s.insert(x);
    } else if (op == 2) {
      if (s.find(x) == s.end()) {
        cout << "0\n";
      } else {
        cout << "1\n";
      }
    } else if (op == 3) {
      auto it = s.upper_bound(x);
      if (it == s.end()) {
        cout << "-1\n";
      } else {
        cout << *it << '\n';
      }
    } else {
      auto it = s.find(x);
      if (it == s.end()) {
        cout << "0\n";
      } else {
        s.erase(it);
        cout << "1\n";
      }
    }
  }
}
