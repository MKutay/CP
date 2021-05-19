#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        if (a[i][j] != 0) {
          cout << "NOT MAGIC\n";
          return 0;
        }
        if (a[i][j] != a[j][i]) {
          cout << "NOT MAGIC\n";
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (a[i][j] > max(a[i][k], a[j][k])) {
          cout << "NOT MAGIC\n";
          return 0;
        }
      }
    }
  }
  cout << "MAGIC\n";
}
