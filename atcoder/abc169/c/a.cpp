/**
 *  author: MKutayBozkurt
 *  created: 09.03.2021 08:51:26
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long a; cin >> a;
  float c; cin >> c;
  long long b = c * 100.0 + 0.1;
  cout << b * a / 100 << '\n';
}
