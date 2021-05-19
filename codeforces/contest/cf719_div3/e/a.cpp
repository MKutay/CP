/**
 *  author: MKutayBozkurt
 *  created: 05.05.2021 17:37:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string S; cin >> S;
    int cnt = 0;
    for (char c : S) cnt += (c == '*' ? 1 : 0);
    int pos = -1;
    int cur = -1;
    for (int i = 0; i < N; i++) {
      if (S[i] == '*') {
        cur++;
        if (cur == cnt / 2) {
          pos = i;
        }
      }
    }
    long long ans = 0;
    cur = pos - cnt / 2;
    for (int i = 0; i < N; i++) {
      if (S[i] == '*') {
        ans += abs(cur - i);
        cur++;
      }
    }
    cout << ans << '\n';
  }
}
