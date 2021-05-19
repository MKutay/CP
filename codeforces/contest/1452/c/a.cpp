#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int n = s.size();
    //vector<pair<int, int>> b(2);
    vector<int> b(2);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        b[0]++;
      } else if (s[i] == ')') {
        if (b[0] > 0) {
          b[0]--;
          ans++;
        }
      } else if (s[i] == '[') {
        b[1]++;
      } else if (s[i] == ']') {
        if (b[1] > 0) {
          b[1]--;
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
