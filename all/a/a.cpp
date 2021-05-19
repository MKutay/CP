#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("yemek.gir", "r", stdin);
  freopen("yemek.cik", "w", stdout);
  int N; cin >> N;
  vector<pair<int, int>> A(N);
  for (auto x : A) cin >> x.first >> x.second;
  long long ans = 1e17;
  for (int m = 1; m <= (1 << N); m++) {
    int b = 0, l = 1;
    for (int i = 0; i < N; i++) {
      if (m & (1 << i)) {
        l *= A[i].first;
        b += A[i].second;
      }
    }
    ans = min(ans, (long long) abs(l - b));
  }
  cout << ans << '\n';
}
