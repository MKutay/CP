/**
 *  author: MKutayBozkurt
 *  created: 27.12.2020 09:02:03
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M; cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  int mn = INT_MAX;
  for (auto &x : A) {
    for (auto &y : x) {
      cin >> y;
      mn = min(mn, y);
    }
  }
  long long ans = 0;
  for (auto x : A) {
    for (auto y : x) {
      ans += y - mn;
    }
  }
  cout << ans << '\n';
}
