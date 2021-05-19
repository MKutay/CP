/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:32:49
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  long long ans = 0;
  for (int i = 5; i <= N; i *= 5) {
    ans += N / i;
  }
  cout << ans << '\n';
}
