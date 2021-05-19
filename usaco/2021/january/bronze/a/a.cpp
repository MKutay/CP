/**
 *  author: MKutayBozkurt
 *  created: 24.01.2021 14:37:46
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string A, S; cin >> A >> S;
  int i = 0;
  int j = 0;
  int ans = 0;
  while (1) {
    if (j >= S.size()) break;
    if (i >= A.size()) {
      i = 0;
      ans++;
      continue;
    }
    if (A[i] == S[j]) {
      j++;
    }
    i++;
  }
  cout << ans + 1 << '\n';
}
