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
    string s;
    int ind = 0;
    if (n > 45) {
      cout << "-1\n";
      continue;
    }
    while (n > 0 && ind < 100) {
      for (int i = 9; i >= 1; i--) {
        if (n < i) continue;
        bool flag = 1;
        for (char c : s) {
          if ((int) c == '0' + i) {
            flag = 0;
            break;
          }
        }
        if (flag) {
          s += '0' + i;
          n -= i;
          break;
        }
      }
      ind++;
    }
    sort(s.begin(), s.end());
    cout << s << '\n';
  }
}
