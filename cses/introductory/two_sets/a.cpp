/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:14:54
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  if ((N * (N + 1) / 2) & 1) {
    cout << "NO\n";
    return 0;
  }
  vector<int> a, b;
  int k = (N % 4 ? 3 : 4);
  for (int i = 0; i < (N - 1) / 4; i++) {
    a.emplace_back(4 * i + 1 + k);
    a.emplace_back(4 * i + 4 + k);
    b.emplace_back(4 * i + 2 + k);
    b.emplace_back(4 * i + 3 + k);
  }
  if (N % 4) {
    a.emplace_back(1);
    a.emplace_back(2);
    b.emplace_back(3);
  } else {
    a.emplace_back(1);
    a.emplace_back(4);
    b.emplace_back(2);
    b.emplace_back(3);
  }
  cout << "YES\n";
  cout << a.size() << '\n';
  for (int x : a) cout << x << " ";
  cout << '\n';
  cout << b.size() << '\n';
  for (int x : b) cout << x << " ";
}
