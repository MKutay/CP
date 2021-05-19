#include <bits/stdc++.h>
using namespace std;

struct item {
  int s, d, c;
  int idx;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<item> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].s >> a[i].d >> a[i].c;
    a[i].s--;
    a[i].d--;
    a[i].idx = i + 1;
  }

  vector<int> ans(n);
  vector<item> cur;
  for (int d = 0; d < n; d++) {
    for (auto y : a) {
      if (y.s == d) {
        cur.emplace_back(y);
      }
    }

    bool exam = 0;
    for (auto &y : cur) {
      if (y.d == d) {
        if (y.c || exam) {
          cout << "-1\n";
          return 0;
        }
        ans[d] = m + 1;
        exam = 1;
      }
    }
    if (!exam) {
      int best = -1;
      for (int i = 0; i < (int) cur.size(); i++) {
        auto &e = cur[i];
        if (e.d > d && e.c > 0 && (best == -1 || cur[best].d > e.d)) {
          best = i;
        }
      }
      if (best >= 0) {
        ans[d] = cur[best].idx;
      } else {
        ans[d] = 0;
      }
    }
  }

  bool ok = 1;
  for (auto &c : cur) {
    if (c.c > 0) ok = 0;
  }

  if (ok) {
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  } else {
    cout << "-1\n";
  }
}
