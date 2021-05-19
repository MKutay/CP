/**
 *  author: MKutayBozkurt
 *  created: 06.03.2021 11:30:36
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, K; cin >> N >> K;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
  sort(A.begin(), A.end());
  set<pair<int, int>> s;
  vector<pair<int, int>> res;
  for (int i = 0, j = 0; i < N && res.size() < 2; i++) {
    cout << i << endl;
    for ( ; A[j].first + K <= A[i].first; j++) {
      s.erase({A[j].second, j});
    }
    auto it1 = s.insert({A[i].second, i}).first;
    auto it2 = it1;
    if (it1-- != s.begin() && A[i].second < it1->first + K) {
      res.emplace_back(i, it1->second);
    }
    if (it2-- != s.begin() && it2->first < A[i].second + K) {
      res.emplace_back(i, it2->second);
    }
  }
  long long ans = 0;
  if (res.size() > 1) {
    ans = -1;
  } else if (res.size()) {
    int dx = A[res[0].first].first - A[res[0].second].first;
    int dy = A[res[0].first].second - A[res[0].second].second;
    dx = abs(dx);
    dy = abs(dy);
    ans = 1ll * (K - dx) * (K - dy);
  }
  cout << ans << '\n';
}
