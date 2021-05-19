/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:18
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, Q; cin >> N >> Q;
    vector<int> A(N); for (int &x : A) cin >> x;

    int sum = 0;
    vector<int> pre, ind;
    for (int i = 0; i < N; i++) {
      sum += A[i];
      if (pre.empty() || sum > pre.back()) {
        pre.emplace_back(sum);
        ind.emplace_back(i);
      }
    }

    while (Q--) {
      int X; cin >> X;
      if (pre.back() < X && sum <= 0) {
        cout << "-1 ";
        continue;
      }
      int times = 0;
      if (pre.back() < X) {
        times = (X - pre.back() + sum - 1) / sum;
      }
      X -= times * sum;
      cout << times * N + ind[lower_bound(pre.begin(), pre.end(), X) - pre.begin()] << " ";
    }
    cout << '\n';
  }
}
