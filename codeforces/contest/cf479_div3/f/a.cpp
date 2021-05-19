#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  map<int, int> m;
  int ans = 0;
  int ind = 0;
  for (int i = 0; i < n; i++) {
    m[a[i]] = m[a[i] - 1] + 1;
    if (ans < m[a[i]]) {
      ans = m[a[i]];
      ind = a[i];
    }
  }

  vector<int> res;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == ind) {
      res.emplace_back(i);
      ind--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res.size() << '\n';
  for (int x : res) {
    cout << x + 1 << " ";
  }
  cout << '\n';
}
