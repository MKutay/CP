/**
 *  author: MKutayBozkurt
 *  created: 01.04.2021 08:26:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  rotate(s.begin(), s.begin() + 1, s.end());
  cout << s << '\n';
}
