/**
 *  author: MKutayBozkurt
 *  created: 01.12.2020 18:26:27
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    int p = 0;
    while (N > 0) N -= ++p;
    if (N == -1) p++;
    cout << p << '\n';
  }
}
