#include <bits/stdc++.h>
using namespace std;

bool f(int x) {
  return x && (!(x & (x - 1)));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  vector<int> ans = {a[0]};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 31; j++) {
      int lx = a[i] - (1 << j);
      int rx = a[i] + (1 << j);
      bool isl = binary_search(a.begin(), a.end(), lx);
      bool isr = binary_search(a.begin(), a.end(), rx);
      if (isl && isr && (int) ans.size() < 3) {
        ans = {lx, a[i], rx};
      }
      if (isl && (int) ans.size() < 2) {
        ans = {lx, a[i]};
      }
      if (isr && (int) ans.size() < 2) {
        ans = {rx, a[i]};
      }
    }
  }
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x << " ";
  }
  cout << '\n';
}
