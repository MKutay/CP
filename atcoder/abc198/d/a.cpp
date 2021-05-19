/**
 *  author: MKutayBozkurt
 *  created: 23.04.2021 21:02:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<string> s(3);
  vector<vector<int>> a(3);
  for (int i = 0; i < 3; i++) cin >> s[i];
  map<char, int> m;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < s[i].size(); j++) {
      m[s[i][j]]++;
      a[i].emplace_back(s[i][j] - 'a');
    }
  }
  int sum = 0;
  for (char i = 'a'; i <= 'z'; i++) {
    sum += m[i];
  }
  if (sum > 11) {
    cout << "UNSOLVABLE\n";
    return 0;
  }
}
