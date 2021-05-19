/**
 *  author: MKutayBozkurt
 *  created: 05.05.2021 17:37:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    string S; cin >> S;
    map<char, int> m;
    bool flag = 0;
    for (int i = 1; i < n; i++) {
      if (S[i] != S[i - 1]) {
        m[S[i - 1]] = 1;
      }
      if (m[S[i]]) {
        cout << "NO\n";
        flag = 1;
        break;
      }
    }
    if (!flag) {
      cout << "YES\n";
    }
  }
}
