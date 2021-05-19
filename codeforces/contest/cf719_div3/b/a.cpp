/**
 *  author: MKutayBozkurt
 *  created: 05.05.2021 17:37:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    string s = to_string(n);
    int x = s.size();
    int ans = (x - 1) * 9;
    for (int i = 1; i <= 9; i++) {
      string t;
      for (int j = 0; j < x; j++) {
        t += i + '0';
      }
      int c = stoi(t);
      if (c >= (int) 1e9) break;
      ans += (c <= n);
    }
    cout << ans << '\n';
  }
}
