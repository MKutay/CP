/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:17
**/
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N); for (int &x : A) cin >> x;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
      m[A[i]]++;
    }
    vector<pair<int, int>> s;
    set<int> vals;
    for (auto x : m) {
      s.emplace_back(x);
      vals.insert(x.second);
    }

    long long ans = INT_MAX;
    for (int c : vals) {
      long long res = 0;
      for (int i = 0; i < (int) s.size(); i++) {
        if (c > s[i].second) {
          res += s[i].second;
        } else if (c < s[i].second) {
          res += (s[i].second - c);
        }
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
}
