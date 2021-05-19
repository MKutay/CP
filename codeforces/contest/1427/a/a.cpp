#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    int s = accumulate(a.begin(), a.end(), 0);
    if (s == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (s > 0) {
      reverse(a.begin(), a.end());
    }
    for (int x : a) cout << x << " ";
    cout << '\n';
  }
}
