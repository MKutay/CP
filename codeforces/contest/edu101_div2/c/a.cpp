/**
 *  author: MKutayBozkurt
 *  created: 29.12.2020 18:35:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) { [] {
    int N, K; cin >> N >> K;
    vector<int> H(N); for (int &x : H) cin >> x;
    for (int i = 0; i < N; i++) {
      if (H[i] >= i * (K - 1)) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
  }(); }
}
