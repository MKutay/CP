#include "bits/stdc++.h"
using namespace std;

#define int long long
const int mod = 998244353;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
  a = a * (a + 1) / 2 % mod;
  b = b * (b + 1) / 2 % mod;
  c = c * (c + 1) / 2 % mod;
  cout << a * b % mod * c % mod << '\n';
}
