#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<int> a(n); for (int &x : a) cin >> x;
  set<int> s;
  for (int x : a) s.insert(x);
  vector<int> b;
  for (int x : s) b.emplace_back(x);
  n = b.size();
  int ans = INT_MAX;
  for (int i = 0; i < n - 1; i++) {
    ans = min(ans, b[i] + m - b[i + 1]);
  }
  ans = min(ans, b[n - 1] + m - b[n - 1]);
  ans = min(ans, b[n - 1] - b[0]);
  for (int i = 1; i < n; i++) {
    ans = min(ans, m - b[i] + b[i - 1]);
  }
  if (s.size() == 1) cout << "0\n";
  else cout << ans << '\n';
}
