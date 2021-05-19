#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(N));
  vector<vector<int>> r(2, vector<int>(N));
  vector<vector<int>> c(2, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      r[i & 1][j] += A[i][j];
      c[j & 1][i] += A[i][j];
    }
  }

  long long R = 0, C = 0;
  for (int i = 0; i < N; i++) {
    R += max(r[0][i], r[1][i]);
    C += max(c[0][i], c[1][i]);
  }
  cout << max(R, C) << '\n';
}
