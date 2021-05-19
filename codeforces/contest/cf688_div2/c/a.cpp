/**
 *  author: MKutayBozkurt
 *  created: 03.04.2021 12:43:31
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K; cin >> N >> K;
  string S; cin >> S;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    a[i] = (S[i] == '?' ? -1 : S[i] - '0');
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) solve();
}
