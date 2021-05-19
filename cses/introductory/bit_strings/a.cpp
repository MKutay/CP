/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:30:17
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= 2;
    if (ans > 1e9 + 7) ans -= 1e9 + 7;
  }
  cout << ans << '\n';
}
