/**
 *  author: MKutayBozkurt
 *  created: 01.04.2021 08:26:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M; cin >> N >> M;
  int X, Y; cin >> X >> Y, X--, Y--;
  vector<vector<char>> A(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int ans = 0;
  for (int i = X + 1; i < N; i++) {
    if (A[i][Y] == '#') break;
    ans++;
  }
  for (int i = Y + 1; i < M; i++) {
    if (A[X][i] == '#') break;
    ans++;
  }
  for (int i = X - 1; i >= 0; i--) {
    if (A[i][Y] == '#') break;
    ans++;
  }
  for (int i = Y - 1; i >= 0; i--) {
    if (A[X][i] == '#') break;
    ans++;
  }
  cout << ans + 1 << '\n';
}
