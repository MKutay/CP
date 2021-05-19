/**
 *  author: MKutayBozkurt
 *  created: 23.04.2021 21:02:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long R, X, Y; cin >> R >> X >> Y;
  long long d = sqrt((double) X * X + (double) Y * Y);
  if (d == R) cout << "1\n";
  else if (d <= R + R) cout << "2\n";
  else cout << (long long) ceil((double) d / R) << '\n';
}
