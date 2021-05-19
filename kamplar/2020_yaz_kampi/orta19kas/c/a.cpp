#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  map<int, int> m;
  vector<int> a(n); for (int &x : a) cin >> x, m[x]++;
  auto b = a;
  sort(a.begin(), a.end());
  int mx1 = a[n - 1], mx2 = a[n - 2];
  for (int i = 0; i < n; i++) {
    if (b[i] == mx1) {
      if (m[mx1] > 1) {
        cout << mx1 << '\n';
      } else {
        cout << mx2 << '\n';
      }
    } else {
      cout << mx1 << '\n';
    }
  }
}
