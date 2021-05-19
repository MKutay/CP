#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  long long ans = 0;
  while (n--) {
    long long a, b; cin >> a >> b;
    ans += b * (b + 1ll) / 2ll;
    ans -= a * (a - 1ll) / 2ll;
  }
  cout << ans << '\n';
}
