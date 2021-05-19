/**
 *  author: MKutayBozkurt
 *  created: 06.03.2021 17:05:35
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, M; cin >> H >> M;
  string s; cin >> s;
  int h = (s[0] - '0') * 10 + (s[1] - '0');
  int m = (s[3] - '0') * 10 + (s[4] - '0');
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < M; j++) {

    }
    if (i == H - 1) i = 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T: cin >> T;
  while (T--) solve();
}
