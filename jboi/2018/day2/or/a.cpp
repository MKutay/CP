#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen("or.in", "r", stdin);
  //freopen("or.out", "w", stdout);
  int X, n; cin >> X >> n;
  vector<vector<int>> a(n, vector<int>(n)), pre(n, vector<int>(n)); cin >> a;
  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int w = 1; w <= n; w++) {
        for (int h = 1; h <= n; h++) {
          if (i + w > n || j + h > n) continue;
          long long r = 0;
          for (int x = i; x < i + w; x++) {
            for (int y = j; y < j + h; y++) {
              r |= a[x][y];
            }
          }
          if ((long long) X == r) {
            ans = min(ans, w * h);
          }
        }
      }
    }
  }
  cout << (ans == 1e9 ? -1 : ans) << '\n';
}
