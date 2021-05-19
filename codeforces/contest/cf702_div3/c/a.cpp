/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:16
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int N; cin >> N;
  for (int i = 1; i * i * i <= N; i++) {
    int a = i * i * i;
    int b = N - a;
    int c = (int) round(pow(b, 1.0 / 3.0));
    if (c * c * c == b && b != 0) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}
