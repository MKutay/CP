/**
 *  author: MKutayBozkurt
 *  created: 07.02.2021 13:01:40
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, M; cin >> N >> M;
  vector<string> e(N);
  for (int i = 0; i < N; i++) {
    cin >> e[i];
  }
  for (int a = 0; a < N; a++) {
    for (int b = a + 1; b < N; b++) {
      if (e[a][b] == e[b][a]) {
        cout << "YES\n";
        for (int i = 0; i < M + 1; i++) {
          cout << (i & 1 ? a : b) + 1 << " ";
        }
        cout << "\n";
        return;
      }
    }
  }
  if (M % 2 == 0) {
    for (int a = 0; a < N; a++) {
      int b = (a + 1) % N;
      for (int c = 0; c < N; c++) {
        if (c != a && c != b && e[a][b] != e[a][c]) {
          vector<int> ord;
          if (M % 4 == 2) {
            ord.emplace_back(b);
          }
          for (int i = 0; i < M / 4; i++) {
            ord.emplace_back(a);
            ord.emplace_back(b);
          }
          for (int i = 0; i < M / 4; i++) {
            ord.emplace_back(a);
            ord.emplace_back(c);
          }
          ord.emplace_back(a);
          if (M % 4 == 2) {
            ord.emplace_back(c);
          }
          cout << "YES\n";
          for (int x : ord) {
            cout << x + 1 << " ";
          }
          cout << '\n';
          return;
        }
      }
    }
  } else {
    cout << "YES\n";
    for (int i = 0; i < M + 1; i++) {
      cout << (i & 1 ? 1 : 2) << " ";
    }
    cout << '\n';
    return;
  }
  assert(N == 2);
  cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    solve();
  }
}
