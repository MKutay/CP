#include <bits/stdc++.h>
using namespace std;

pair<int, vector<int>> big(int n, int w, vector<pair<int, int>> a) {
  vector<int> ans;
  long long s = 0;
  for (int i = n - 1; i >= 0 && w > 0; i--) {
    if (a[i].first <= w) {
      w -= a[i].first;
      ans.emplace_back(a[i].second);
      s += a[i].first;
    }
  }
  return {s, ans};
}

pair<int, vector<int>> small(int n, int w, vector<pair<int, int>> a) {
  vector<int> ans;
  long long s = 0;
  for (int i = 0; i < n && w > 0; i++) {
    if (a[i].first <= w) {
      w -= a[i].first;
      ans.emplace_back(a[i].second);
      s += a[i].first;
    }
  }
  return {s, ans};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, w; cin >> n >> w;
    int W = w;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    auto ans = small(n, w, a);
    if (ans.first >= ceil(W / 2.0) && ans.first <= W) {
      cout << ans.second.size() << '\n';
      for (int x : ans.second) cout << x + 1 << " ";
      cout << '\n';
    } else {
      auto an2 = big(n, w, a);
      if (an2.first >= ceil(W / 2.0) && an2.first <= W) {
        cout << an2.second.size() << '\n';
        for (int x : an2.second) cout << x + 1 << " ";
        cout << '\n';
      } else {
        cout << "-1\n";
      }
    }
  }
}
