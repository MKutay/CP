/**
 *  author: MKutayBozkurt
 *  created: 20.02.2021 19:47:41
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int, long long> dp, ans;
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int V; cin >> V;
    map<int, long long> m;
    m[V]++;
    ans[V]++;
    for (auto e : dp) {
      m[gcd(e.first, V)] += e.second;
      ans[gcd(e.first, V)] += e.second;
    }
    dp = m;
  }
  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int V; cin >> V;
    cout << ans[V] << '\n';
  }
}
