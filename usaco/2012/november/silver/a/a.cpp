/**
 *  author: MKutayBozkurt
 *  created: 02.03.2021 20:02:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("clumsy.in", "r", stdin);
  //freopen("clumsy.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  string S; cin >> S;
  int N = S.size();
  int s = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    s += (S[i] == '(' ? 1 : -1);
    if (s < 0) {
      ans++;
      s = 1;
    }
  }
  cout << ans + abs(s / 2) << '\n';
}
