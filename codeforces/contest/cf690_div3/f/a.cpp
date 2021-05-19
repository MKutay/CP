/**
 *  author: MKutayBozkurt
 *  created: 16.12.2020 11:08:16
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  vector<int> L, R;
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
    L.emplace_back(A[i].first);
    R.emplace_back(A[i].second);
  }
  sort(L.begin(), L.end());
  sort(R.begin(), R.end());
  int ans = N - 1;
  for (auto [l, r] : A) {
    int left = lower_bound(R.begin(), R.end(), l) - R.begin();
    int right = max(0, N - (int) (upper_bound(L.begin(), L.end(), r) - L.begin()));
    ans = min(ans, left + right);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) solve();
}
