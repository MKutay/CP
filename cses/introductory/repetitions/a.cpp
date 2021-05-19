/**
 *  author: MKutayBozkurt
 *  created: 17.01.2021 21:15:58
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string S; cin >> S;
  int N = S.size();
  int res = 0, ans = 0;
  for (int i = 1; i < N; i++) {
    if (S[i] == S[i - 1]) res++;
    else {
      ans = max(res, ans);
      res = 0;
    }
  }
  ans = max(res, ans);
  cout << ans + 1 << '\n';
}
