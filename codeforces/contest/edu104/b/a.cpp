/**
 *  author: MKutayBozkurt
 *  created: 15.02.2021 20:16:02
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, K; cin >> N >> K;
    if (N & 1) {
      cout << (K - 1 + (K - 1) / (N / 2)) % N + 1 << '\n';
    } else {
      if (K % N == 0) cout << N << '\n';
      else cout << K % N << '\n';
    }
  }
}
