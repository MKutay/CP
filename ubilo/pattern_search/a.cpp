#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int mul(int x, int y) {
  return (x % mod) * (y % mod) % mod;
}

int add(int x, int y) {
  return (x % mod) + (y % mod) % mod;
}

int sub(int x, int y) {
  x = (x % mod) - (y % mod) % mod;
  while (x < 0) {
    x += mod;
  }
  return x;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("pattern.gir", "r", stdin);
  freopen("pattern.cik", "w", stdout);
  string S, T; cin >> S >> T;
  int N = S.size(), M = T.size();
  vector<int> power(M + 1);
  for (int i = 0; i <= M; i++) {
    power[i] = (i == 0 ? 1 : mul(power[i - 1], 31));
  }
  int hs = 0, ht = 0;
  for (int i = 0; i < M; i++) {
    hs = mul(hs, 31);
    hs = add(hs, (int) S[i]);

    ht = mul(ht, 31);
    ht = add(ht, (int) T[i]);
  }

  int ans = 0;

  for (int i = M - 1; i < N; i++) {
    if (hs == ht) {
      ans++;
    }
    hs = sub(hs, mul(power[M - 1], S[i - M + 1]));
    hs = mul(hs, 31);
    hs = add(hs, S[i + 1]);
  }
  cout << ans << '\n';
}

