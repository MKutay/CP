/**
 *  author: MKutayBozkurt
 *  created: 17.01.2021 21:32:13
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  if (N == 1) {
    cout << "1\n";
    return 0;
  }
  if (N < 4) {
    cout << "NO SOLUTION\n";
    return 0;
  }
  if (N == 4) {
    cout << "2 4 1 3\n";
    return 0;
  }
  vector<int> a;
  for (int i = 0; i < N; i++) {
    if ((i + 1) & 1) {
      a.emplace_back(i + 1);
    }
  }
  for (int i = 0; i < N; i++) {
    if ((i + 1) % 2 == 0) {
      a.emplace_back(i + 1);
    }
  }
  for (int &x : a) {
    cout << x << " ";
  }
}
