#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mn = *min_element(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    a[i] -= mn - 1;
  }
  int ans = 0;
  if (n & 1) {
    for (int i = 0; i < n / 2; i++) {
      ans += (a[i] != i + 1);
    }
    ans += (a[n / 2] != n / 2 + 1);
    int b = n / 2;
    for (int i = n / 2 + 1; i < n; i++) {
      ans += (a[i] != b);
      b--;
    }
  } else {
    for (int i = 0; i < n / 2; i++) {
      ans += (a[i] != i + 1);
    }
    int b = n / 2;
    for (int i = n / 2; i < n; i++) {
      ans += (a[i] != b);
      b--;
    }
  }
  cout << ans << '\n';
}
