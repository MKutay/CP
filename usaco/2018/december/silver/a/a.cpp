/**
 *  author: MKutayBozkurt
 *  created: 25.02.2021 08:08:43
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);
  int N, M, C; cin >> N >> M >> C;
  vector<int> A(N); for (int &x : A) cin >> x;
  sort(A.begin(), A.end());
  auto check = [&](int m) {
    int w = 1;
    int farr = A[0];
    int ind = 0;
    for (int i = 1; i < N; i++) {
      if (A[i] - farr > m || i + 1 - ind > C) {
        w++;
        farr = A[i];
        ind = i;
      }
    }
    return (w <= M);
  };
  int l = 0, r = 1e9 + 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << '\n';
}
