#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'F') {
      ans = i;
      break;
    }
  }
  bool f = 0;
  for (int i = 0; i < ans; i++) {
    if (s[i] == 'M') {
      f = 1;
      break;
    }
  }
  if (!f) {
    cout << "0\n";
    return 0;
  }
  int ans2 = 0;
  for (int i = ans - 1; i >= 0; i--) {
    if (s[i] == 'F' && s[i + 1] == 'F') ans2--;
    if (s[i] == 'F') {
      ans2++;
    }
  }
  if (ans2 < 0) {
    cout << 0 << '\n';
    return 0;
  }
  cout << max(0, ans - ans2) << '\n';
}
