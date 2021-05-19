/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 20:43:33
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, G, B; cin >> N >> G >> B;
    int g = (N + 1) / 2;
    int tot = g / G * (B + G);
    tot += (g % G == 0 ? -B : g % G);
    cout << max(N, tot) << '\n';
  }
}
