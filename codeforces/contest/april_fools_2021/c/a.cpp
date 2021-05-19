/**
 *  author: MKutayBozkurt
 *  created: 01.04.2021 17:35:54
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  for (int i = 0; i < (int) s.size() - 2; i++) {
    int a = s[i] - 'A';
    int b = s[i + 1] - 'A';
    int c = s[i + 2] - 'A';
    if (26 - a + 26 - b != 26 - c && a + b != c) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
}
