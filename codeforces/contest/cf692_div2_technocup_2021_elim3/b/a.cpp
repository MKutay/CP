/**
 *  author: MKutayBozkurt
 *  created: 23.12.2020 11:51:32
**/
#include <bits/stdc++.h>
using namespace std;

int check(long long N) {
  long long n = N;
  while (n > 1) {
    if (n % 10 != 0 && (N % (n % 10) != 0)) return 0;
    n /= 10;
  }
  return 1;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    long long N; cin >> N;
    while (!check(N)) N++;
    cout << N << '\n';
  }
}
