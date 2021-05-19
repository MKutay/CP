#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> m;
  int ans = 0;
  for (int i = 0; i < (n + 1) / 2; i++) {
    m[a[i] - i]++;
  }
  reverse(a.begin(), a.end());
  for (int i = 0; i < n / 2; i++) {
    m[a[i] - i]++;
  }
  for (auto p : m) {
    if (p.first > 0) ans = max(ans, p.second);
  }
  cout << n - ans << '\n';
}

