/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 21:10:39
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int R, D; cin >> R >> D;
  int N; cin >> N;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int x, y, r; cin >> x >> y >> r;
    if (sqrt(x * x + y * y) + r <= R && sqrt(x * x + y * y) >= R - D + r) ans++;
  }
  cout << ans << '\n';
}
