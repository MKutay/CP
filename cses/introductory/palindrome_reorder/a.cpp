/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:47:19
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string S; cin >> S;
  int n = S.size();
  map<char, int> m;
  for (int i = 0; i < n; i++) {
    m[S[i]]++;
  }
  string f = "", b = "";
  int odd = 0;
  string odds;
  for (char i = 'A'; i <= 'Z'; i++) {
    if (m[i] & 1) {
      for (int j = 0; j < m[i]; j++) {
        odds += i;
      }
      odd++;
    } else {
      for (int j = 0; j < m[i] / 2; j++) {
        f += i;
        b += i;
      }
    }
  }
  if (odd > 1) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  reverse(b.begin(), b.end());
  if (odd == 0) cout << f << b << '\n';
  else cout << f << odds << b << '\n';
}
