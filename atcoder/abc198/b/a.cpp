/**
 *  author: MKutayBozkurt
 *  created: 23.04.2021 21:02:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  while (s.back() == '0') {
    s.pop_back();
  }
  string t = s;
  reverse(t.begin(), t.end());
  if (t == s) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
