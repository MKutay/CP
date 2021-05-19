#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  char w = 'a';
  string ans;
  for (int j = n - 1; j >= 0; j--) {
    if (a[j]) {
      for (int i = 0; i < a[j]; i++) {
        ans += string(j + 1, w);
        if (w == 'a') w = 'b';
        else w = 'a';
      }
      for (int i = j - 1; i >= 0; i--) {
        a[i] -= a[j] * (j - i + 1);
      }
    }
  }
  cout << ans << '\n';
}
