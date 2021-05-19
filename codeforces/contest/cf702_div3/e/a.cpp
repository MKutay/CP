/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:17
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  vector<int> ans;
  sort(A.begin(), A.end());
  vector<int> pre(N + 1);
  for (int i = 0; i < N; i++) {
    pre[i + 1] = pre[i] + A[i].first;
  }
  ans.emplace_back(A.back().second);
  int ind = N - 1;
  while (ind > 0 && pre[ind] >= A[ind].first) {
    ind--;
    ans.emplace_back(A[ind].second);
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}
