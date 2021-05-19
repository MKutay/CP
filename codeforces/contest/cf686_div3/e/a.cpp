#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

void solve() {
  int N; cin >> N;
  g = vector<vector<int>>(N);
  for (int i = 0; i < N; i++) {
    int X, Y; cin >> X >> Y, X--, Y--;
    g[X].emplace_back(Y);
    g[Y].emplace_back(X);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) solve();
}
