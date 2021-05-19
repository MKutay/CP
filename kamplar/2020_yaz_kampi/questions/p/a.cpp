#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  while (n != 0) {
    int lv = floor(log(n));
    vector<int> p; // 0 = l, 1 = r
    while (n > 1) {
      if (n & 1) {
        n--;
        n = n / 2;
        p.emplace_back(1);
      } else {
        n = n / 2;
        p.emplace_back(0);
      }
    }
    reverse(p.begin(), p.end());
    int a = 1, b = 1;
    for (int x : p) {
      if (x == 0) {
        b = a + b;
      } else {
        a = a + b;
      }
    }
    cout << a << "/" << b << '\n';
    cin >> n;
  }
}
