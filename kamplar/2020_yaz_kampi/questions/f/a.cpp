#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree, good, a, lis;

void update(int i, int d) {
  while (i < n + 1) {
    tree[i] = max(tree[i], d);
    i += i & -i;
  }
}

int get(int i) {
  int s = 0;
  while (i > 0) {
    s = max(s, tree[i]);
    i -= i & -i;
  }
  return s;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t = 10;
  while (t--) {
    cin >> n;
    a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    tree = vector<int>(n + 1);
    good = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) {
      lis[i] = get(a[i] - 1) + 1;
      update(a[i], lis[i]);
    }
    int mxLis = 0;
    for (int i = 1; i <= n; i++) {
      mxLis = max(mxLis, lis[i]);
    }

    vector<vector<pair<int, int>>> f(mxLis + 1);
    vector<vector<int>> cand(mxLis + 1);
    for (int i = 1; i <= n; i++) {
      if (lis[i] == mxLis) {
        f[mxLis].emplace_back(i, a[i]);
        good[i] = 1;
      } else {
        cand[lis[i]].emplace_back(i);
      }
    }
    for (int i = mxLis - 1; i > 0; i--) {
      for (int j = (int) f[i + 1].size() - 2; j >= 0; j--) {
        f[i + 1][j].second = max(f[i + 1][j].second, f[i + 1][j + 1].second);
      }
      for (int cnd : cand[i]) {
        auto it = lower_bound(f[i + 1].begin(), f[i + 1].end(), make_pair(cnd, -1));
        if (it != f[i + 1].end() && (*it).second > a[cnd]) {
          f[i].emplace_back(cnd, a[cnd]);
          good[cnd] = 1;
        }
      }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
      if (good[i]) {
        res.emplace_back(a[i]);
      }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int x : res) {
      cout << x << '\n';
    }
  }
}
