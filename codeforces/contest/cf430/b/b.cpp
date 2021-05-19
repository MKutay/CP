/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 21:10:39
**/
#include <bits/stdc++.h>
using namespace std;

struct item {
  int x, y, r;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int R, D; cin >> R >> D;
  int N; cin >> N;
  vector<item> A(N);
  int ans = -1;
  for (int i = 0; i < N; i++) {
    cin >> A[i].x >> A[i].y >> A[i].r;
    if (sqrt(A[i].x * A[i].x + A[i].y * A[i].y) <= R && sqrt(A[i].x * A[i].x + A[i].y * A[i].y) >= R - D + A[i].r) {
      ans++;
    }
  }
  cout << max(0, ans) << '\n';
}

