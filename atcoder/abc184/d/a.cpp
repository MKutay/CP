#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
  double ans = 0;
  ans += (100 - a) * ((double) a / (a + b + c));
  ans += (100 - b) * ((double) b / (a + b + c));
  ans += (100 - c) * ((double) c / (a + b + c));
  cout << fixed << setprecision(10) << ans << '\n';
}
