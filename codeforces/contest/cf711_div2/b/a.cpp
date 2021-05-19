/**
 *  author: kutay
 *  created: 29.03.2021 17:36:01
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, W; cin >> N >> W;
    vector<int> A(N); for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    map<int, int> m;
    for (int x : A) m[x]++;
    set<int> s;
    for (int x : A) s.insert(x);

    int ans = 0;

    while (s.size()) {
      int w = W;
      while (s.size() && w > 0) {
        auto it = s.lower_bound(w);
        if (it == s.end()) {
          it--;
        }
        int i = *it;
        int x = i;
        if (x > w) break;
        w -= x;
        m[x]--;
        if (m[x] < 0) assert(false);
        if (m[x] == 0) {
          s.erase(x);
        }
      }
      ans++;
    }
    cout << ans << '\n';
  }
}
