/**
 *  author: MKutayBozkurt
 *  created: 29.12.2020 18:35:15
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    string S; cin >> S;
    int n = S.size();
    if (n % 2 == 0 && S[0] != ')' && S[n - 1] != '(') {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
