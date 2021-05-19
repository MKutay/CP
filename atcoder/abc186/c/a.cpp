/**
 *  author: MKutayBozkurt
 *  created: 27.12.2020 09:02:03
**/
#include <bits/stdc++.h>
using namespace std;

int is10(int x) {
  while (x > 0) {
    if (x % 10 == 7) return 0;
    x /= 10;
  }
  return 1;
}

int is7(int x) {
  while (x > 0) {
    if (x % 8 == 7) return 0;
    x /= 8;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (is10(i) && is7(i)) ans++;
  }
  cout << ans << '\n';
}
