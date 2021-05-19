#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  vector<long long> c(N);
  for (int i = 0; i < N; i++) {
    c[i] = (i + 1) * (N - i) * (long long) A[i];
  }
  sort(c.begin(), c.end());
  sort(B.rbegin(), B.rend());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += ((c[i] % mod) * (B[i]) % mod) % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}
