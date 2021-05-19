/**
 *  author: MKutayBozkurt
 *  created: 31.01.2021 16:10:38
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  if (N < 25) {
    cout << "-1\n";
    return 0;
  }
  int a = -1, b = -1;
  for (int i = 5; i < N; i++) {
    if (N % i == 0 && N / i >= 5) {
      a = i;
      b = N / i;
      break;
    }
  }
  if (a == -1 || b == -1) {
    cout << "NO\n";
    return 0;
  }
  vector<char> vow = {'a', 'e', 'i', 'o', 'u'};
  vector<vector<char>> ans(a, vector<char>(b, 'z'));
  for (int i = 0; i < vow.size(); i++) {
    for (int j = 0; j < vow.size(); j++) {
      ans[i][j] = vow[j];
    }
    rotate(vow.begin(), vow.begin() + 1, vow.end());
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << ans[i][j];
    }
  }
}
