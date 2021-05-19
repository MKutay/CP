/**
 *  author: kutay
 *  created: 30.03.2021 14:16:32
**/
#include <bits/stdc++.h>
using namespace std;

struct itm {
  int v, w, d;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, K; cin >> N >> K;
  vector<vector<itm>> g(N + 1);

  for (int i = 1; i <= N; i++) {
    int w, v, d; cin >> w >> v >> d;
    g[i].emplace_back(itm{v, w, d});
  }
}
