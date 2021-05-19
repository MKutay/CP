/**
 *  author: MKutayBozkurt
 *  created: 19.12.2020 12:35:30
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  if (N & 1) {
    cout << (2 * (N / 2 + 1) * (N / 2 + 2)) << '\n';
  } else {
    cout << (N / 2 + 1) * (N / 2 + 1) << '\n';
  }
}
