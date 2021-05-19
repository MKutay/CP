#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  for (int k = 1; k <= 10; k++) {
    auto b = a;
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < n; j++) {
        if (j == 0) {
          b[j] = b[j] & b[j + 1];
        } else if (j == n - 1) {
          b[j] = b[j] & b[j - 1];
        } else {
          b[j] = (b[j] & b[j - 1]) & b[j + 1];
        }
      }
    }
    for (int x : b) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
