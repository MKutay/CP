/**
 *  author: MKutayBozkurt
 *  created: 05.03.2021 20:02:32
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("wifi.in", "r", stdin);
  freopen("wifi.out", "w", stdout);
  int N, A, B; cin >> N >> A >> B;
  vector<int> a(N); for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  int c = 1;
  int len = 0;
  for (int i = 0; i < N - 1; i++) {
    int l = a[i + 1] - a[i];
    if (l * B > 2 * A) {
      c++;
    } else len += l;
  }
  int ans = c * A * 2 + B * len;
  if (ans & 1) {
    cout << ans / 2 << ".5\n";
  } else cout << ans / 2 << '\n';
}
