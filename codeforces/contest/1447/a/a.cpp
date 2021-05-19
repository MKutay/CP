#include <bits/stdc++.h>
using namespace std;


void solve(int n) {
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " ";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    solve(n);
  }
  return 0;
}
