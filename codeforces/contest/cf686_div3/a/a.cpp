#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n & 1) {
      vector<int> ans;
      for (int i = n; i >= 1; i--) {
        ans.emplace_back(i);
      }
      swap(ans[n / 2], ans[n / 2 + 1]);
      for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
      }
      cout << '\n';
    } else {
      for (int i = n; i >= 1; i--) {
        cout << i << " ";
      }
      cout << '\n';
    }
  }
}
