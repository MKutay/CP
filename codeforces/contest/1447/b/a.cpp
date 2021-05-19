#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    long long s = 0;
    int mn = INT_MAX;
    int neg = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] < 0) neg++;
        if (a[i][j] < 0) s += -a[i][j];
        else s += a[i][j];
        mn = min(mn, abs(a[i][j]));
      }
    }
    if (neg & 1) 
      cout << s - mn * 2 << '\n';
    else 
      cout << s << '\n';
  }
}
