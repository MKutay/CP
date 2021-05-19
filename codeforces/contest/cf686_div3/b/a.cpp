#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  map<int, int> m;
  for (int i = 0; i < n; i++) m[a[i].first]++;
  sort(a.begin(), a.end());
  for (auto x : a) {
    if (m[x.first] == 1) {
      cout << x.second + 1 << '\n';
      return;
    }
  }
  cout << "-1\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
