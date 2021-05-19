/**
 *  author: MKutayBozkurt
 *  created: 19.01.2021 08:18:57
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  string s = "";
  for (int i = 0; i < N; i++) s += "0";
  map<string, bool> m;
  cout << s << '\n';
  m[s] = 1;
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      string k = s;
      if (k[j] == '0') k[j] = '1';
      else if (k[j] == '1') k[j] = '0';
      if (m[k] == 0) {
        s = k;
        cout << k << '\n';
        m[k] = 1;
        break;
      }
    }
  }
}
