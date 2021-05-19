/**
 *  author: MKutayBozkurt
 *  created: 23.12.2020 21:00:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  vector<set<int>> a(26);
  for (int i = 0; i < n; i++) {
    a[s[i] - 'a'].insert(i);
  }
  int m; cin >> m;
  while (m--) {
    int op; cin >> op;
    if (op == 1) {
      int pos;
      char c; cin >> pos >> c;
      pos--;
      a[s[pos] - 'a'].erase(pos);
      s[pos] = c;
      a[s[pos] - 'a'].insert(pos);
    } else {
      int l, r; cin >> l >> r; l--, r--;
      int c = 0;
      for (int i = 0; i < 26; i++) {
        auto it = a[i].lower_bound(l);
        if (it != a[i].end() && *it <= r) c++;
      }
      cout << c << '\n';
    }
  }
}
