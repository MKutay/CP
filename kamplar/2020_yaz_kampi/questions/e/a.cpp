#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mx = 1e5 + 25;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> c(mx);
  int n;
  for(int i = 1; i < mx; i++){
    c[i] = i;
    for(int j = 1; j * j * j <= i; j++)
      c[i] = min(c[i], c[i - j * j * j] + 1);
  }
  for (int i = 1; scanf("%lld", &n) != EOF; i++) {
    cout << "Case #" << i << ": " << c[n] << '\n';
  }
}
