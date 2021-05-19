/**
 *  author: MKutayBozkurt
 *  created: 28.11.2020 17:50:10
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> a;
double ans;

double f(int x, int k) {
  return (k * x - a[k]) / (double) (k + 1);
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q; cin >> q;
  a.emplace_back(0);
  int k = 0;
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      while (k + 1 < a.size() && f(x, k + 1) >= f(x, k)) k++;
      ans = max(ans, f(x, k));
      a.emplace_back(a.back() + x);
    } else cout << fixed << setprecision(10) << ans << '\n';
  }
}
