#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m; cin >> n >> m;
  map<char, int> mp;
  for (char i = 'a'; i <= 'z'; i++) {
    cin >> mp[i];
  }
  string s, t; cin >> s >> t;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1]) {
        a[i][j] = a[i - 1][j - 1] + mp[s[i - 1]];
      } else {
        a[i][j] = max(a[i - 1][j], a[i][j - 1]);
      }
    }
  }
  cout << a[n][m] << '\n';
}
