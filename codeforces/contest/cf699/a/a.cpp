/**
 *  author: MKutayBozkurt
 *  created: 07.02.2021 13:01:38
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int X, Y; cin >> X >> Y;
    string S; cin >> S;
    int n = S.size();
    map<char, int> m;
    for (char c : S) {
      m[c]++;
    }
    if (X < 0) {
      if (m['L'] < -X) {
        cout << "NO\n";
        continue;
      }
    } else {
      if (m['R'] < X) {
        cout << "NO\n";
        continue;
      }
    }
    if (Y < 0) {
      if (m['D'] < -Y) {
        cout << "NO\n";
        continue;
      }
    } else {
      if (m['U'] < Y) {
        cout << "NO\n";
        continue;
      }
    }
    cout << "YES\n";
  }
}
