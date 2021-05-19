#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> m;
  vector<int> a(n); for (int &x : a) cin >> x, m[x]++;
  for (int i = 0; i <= 200001; i++) {
    if (!m[i]) {
      cout << i << '\n';
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 1;
  while (t--) solve();
}
