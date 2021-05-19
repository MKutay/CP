#include <bits/stdc++.h>
using namespace std;

bool isp(int n) {
  if (n == 1) return 0;
  if (n == 2) return 1;
  int a = sqrt(n) + 1;
  for (int i = 2; i <= a; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

void solve() {
  int n; cin >> n;
  if (isp(n)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << "1 ";
      }
      cout << '\n';
    }
    return;
  }
  int a = n;
  for (int d = a; d <= 1000; d++) {
    if (isp(d)) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j) {
            cout << d - (n - 1) << " ";
          } else {
            cout << "1 ";
          }
        }
        cout << '\n';
      }
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
