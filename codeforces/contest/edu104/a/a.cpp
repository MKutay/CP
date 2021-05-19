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
    int N; cin >> N;
    vector<int> A(N); for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] != A.front()) ans++;
    }
    cout << ans << '\n';
  }
}
