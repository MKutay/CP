/**
 *  author: MKutayBozkurt
 *  created: 19.01.2021 17:35:35
**/
#include <bits/stdc++.h>
using namespace std;

vector<int> check(int n, vector<int> a, int x) {
  multiset<int> s;
  for (int e : a) s.insert(e);
  vector<int> res;
  for (int i = 0; i < n; i++) {
    auto it1 = s.end();
    it1--;
    int y = x - *it1;
    s.erase(it1);
    auto it2 = s.find(y);
    if (it2 == s.end()) {
      return {};
    }
    res.emplace_back(x - y);
    res.emplace_back(y);
    x = max(x - y, y);
    s.erase(it2);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) [&] {
    int N; cin >> N;
    vector<int> A(2 * N); for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    for (int i = 0; i < 2 * N - 1; i++) {
      int x = A[i] + A[2 * N - 1];
      vector<int> res = check(N, A, x);
      if (res.size()) {
        cout << "YES\n";
        cout << x << '\n';
        for (int j = 0; j < N; j++) {
          cout << res[2 * j] << " " << res[2 * j + 1] << '\n';
        }
        return;
      }
    }
    cout << "NO\n";
  }();
}
