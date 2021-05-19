/**
 *  author: MKutayBozkurt
 *  created: 23.12.2020 11:51:33
**/
#include <bits/stdc++.h>
using namespace std;

struct item {
  int x, y;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vector<item> A(M);
    for (int i = 0; i < M; i++) {
      cin >> A[i].x >> A[i].y;
    }
    sort(A.begin(), A.end(), [&](const item &a, const item &b) {
      return a.x > b.x;
    });
  }
}
