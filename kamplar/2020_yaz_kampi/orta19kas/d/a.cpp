#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int k = i;
    int res = 0;
    for (int j = i; j < n - 1; ) {
      if (a[j + 1] <= a[j]) j++;
      else {
        break;
      }
      k = j;
      res++;
    }
    i = k;
    ans = max(ans, res);
  }
  cout << ans << '\n';
}
