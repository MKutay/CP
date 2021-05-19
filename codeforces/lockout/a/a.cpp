/**
 *  author: MKutayBozkurt
 *  created: 21.02.2021 21:04:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M, K; cin >> N >> M >> K;
  vector<vector<int>> A(N + 10, vector<int>(M + 10));
  for (int i = 0; i < K; i++) {
    int X, Y; cin >> X >> Y, X += 5, Y += 5;
    A[X][Y] = 1;
    if (A[X - 1][Y] && A[X][Y - 1] && A[X - 1][Y - 1]) {
      cout << i + 1 << '\n';
      return 0;
    } else if (A[X + 1][Y] && A[X][Y - 1] && A[X + 1][Y - 1]) {
      cout << i + 1 << '\n';
      return 0;
    } else if (A[X + 1][Y] && A[X][Y + 1] && A[X + 1][Y + 1]) {
      cout << i + 1 << '\n';
      return 0;
    } else if (A[X - 1][Y] && A[X][Y + 1] && A[X - 1][Y + 1]) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << "0\n";
}
