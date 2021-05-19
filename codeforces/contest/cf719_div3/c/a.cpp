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
    if (n == 1) {
      cout << "1\n";
      continue;
    }
    if (n == 2) {
      cout << "-1\n";
      continue;
    }
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    int last = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j && i == 0) {
          a[i][j] = 1;
          last = 1;
          continue;
        }
        a[i][j] = last + 2;
        last += 2;
        if (a[i][j] == n * n || a[i][j] == n * n - 1) {
          last = 0;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}
