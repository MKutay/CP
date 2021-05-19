/**
 *  author: MKutayBozkurt
 *  created: 29.12.2020 18:35:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> R(N); for (int &x : R) cin >> x;
    int M; cin >> M;
    vector<int> B(M); for (int &x : B) cin >> x;
    vector<int> r(N), b(M);
    for (int i = 0; i < N; i++) {
      r[i] = (i == 0 ? R[i] : r[i - 1] + R[i]);
    }
    for (int i = 0; i < M; i++) {
      b[i] = (i == 0 ? B[i] : b[i - 1] + B[i]);
    }
    int ans = max(0, *max_element(r.begin(), r.end())) + max(0, *max_element(b.begin(), b.end()));
    cout << ans << '\n';
  }
}
