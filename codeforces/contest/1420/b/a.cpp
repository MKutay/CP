#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    vector<int> cnt(32);
    for (int i = 0; i < n; i++) {
      int b = __builtin_clz(a[i]);
      cnt[b]++;
    }
    long long ans = 0;
    for (int b = 0; b < 32; b++) {
      ans += (long long) cnt[b] * (cnt[b] - 1) / 2;
    }
    cout << ans << '\n';
  }
}
