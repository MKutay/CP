#include "bits/stdc++.h"
using namespace std;

void solve() {
  char c; cin >> c;
  char x; cin >> x;
  if (c == 'Y') {
    cout << (char) (x - 32) << '\n';
  } else {
    cout << x << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}
