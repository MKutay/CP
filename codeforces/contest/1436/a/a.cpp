#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> a(n); for (int &x : a) cin >> x;
    long long s = accumulate(a.begin(), a.end(), 0ll);
    if (s == m) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
