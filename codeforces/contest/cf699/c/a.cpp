/**
 *  author: MKutayBozkurt
 *  created: 07.02.2021 13:01:39
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M; cin >> N >> M;
  vector<int> A(N); for (int &x : A) cin >> x;
  vector<int> B(N); for (int &x : B) cin >> x;
  vector<int> C(M); for (int &x : C) cin >> x;
  vector<int> change;
  for (int i = 0; i < N; i++) {
    if (A[i] != B[i]) {
      change.emplace_back(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}
