/**
 *  author: MKutayBozkurt
 *  created: 01.04.2021 08:26:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<long long> A(N); for (auto &x : A) cin >> x;
  long long ans = 1e18;
  for (int i = 0; i < (1 << N); i++) {
    long long ored = 0, xored = 0;
    for (int j = 0; j < N; j++) {
      int k = i & (1 << j);
      ored |= A[j];
      if (k) {
        xored ^= ored;
        ored = 0;
      }
    }
    xored ^= ored;
    ans = min(ans, xored);
  }
  cout << ans << '\n';
}
