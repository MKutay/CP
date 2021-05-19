#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if ((s[i] == '0' && s[j] == '0') ||
          (s[i] == '2' && s[j] == '5') ||
          (s[i] == '5' && s[j] == '0') ||
          (s[i] == '7' && s[j] == '5')) {
        int d = abs(n - i - 2) + abs(n - j - 1);
        if (j < i) {
          d = abs(n - j - 2) + abs(n - i - 1) + 1;
        }
        if (i == 0 || j == 0) {
          int k = 1;
          while (k < max(i, j) && s[k] == '0') k++, d++;
        }
        ans = min(ans, d);
      } 
    }
  }
  cout << (ans == INT_MAX ? -1 : ans) << '\n';
}
