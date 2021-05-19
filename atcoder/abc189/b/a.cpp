/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 15:00:12
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, X; cin >> N >> X;
  X *= 100;
  int amount = 0;
  for (int i = 0; i < N; i++) {
    int v, p; cin >> v >> p;
    amount += v * p;
    if (amount > X) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
