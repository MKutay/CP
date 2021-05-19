/**
 *  author: MKutayBozkurt
 *  created: 16.12.2020 11:08:13
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string s; cin >> s;
    bool flag = 0;
    for (int i = 0; i <= 4; i++) {
      string f = s.substr(0, i) + s.substr(n - (4 - i));
      if (f == "2020") {
        flag = 1;
      }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
  }
}
