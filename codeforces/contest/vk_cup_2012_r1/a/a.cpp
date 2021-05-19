/**
 *  author: MKutayBozkurt
 *  created: 20.01.2021 19:04:41
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M, X, Y; cin >> N >> M >> X >> Y;
  vector<pair<int, int>> A(N), B(M);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i].first;
    B[i].second = i;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int i1 = 0, i2 = 0;
  vector<pair<int, int>> ans;
  for (; i1 < N; i1++) {
    for (; i2 < M; i2++) {
      if (A[i1].first - X > B[i2].first) continue;
      break;
    }
    if (i2 < M && A[i1].first + Y >= B[i2].first && A[i1].first - X <= B[i2].first) {
      ans.emplace_back(A[i1].second, B[i2].second);
      i2++;
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second + 1 << '\n';
  }
}
