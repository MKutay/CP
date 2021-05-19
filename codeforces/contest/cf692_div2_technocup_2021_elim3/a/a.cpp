/**
 *  author: MKutayBozkurt
 *  created: 23.12.2020 11:51:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string S; cin >> S;
    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (S[i] != ')') break;
      ans++;
    }
    if (ans > N - ans) cout << "Yes\n";
    else cout << "No\n";
  }
}
