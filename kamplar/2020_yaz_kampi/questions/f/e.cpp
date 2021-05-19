#include <bits/stdc++.h>
using namespace std;

struct segtree {
  vector<int> tree;
  int query(int node, int l, int r, int xl, int xr) {
    if (l > xr || r < xl) return 0;
    if (l >= xl && r <= xr) return tree[node];
    int m = (l + r) / 2;
    int L = query(2 * node, l, m, xl, xr);
    int R = query(2 * node + 1, m + 1, r, xl, xr);
    return max(L, R);
  }
  void update(int node, int l, int r, int i, int val) {
    if (l == r && l == i) {
      tree[node] = val;
      return;
    }
    if (l > i || r < i) return;
    int m = (l + r) / 2;
    update(2 * node, l, m, i, val);
    update(2 * node + 1, m + 1, r, i, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
  }
};

int main() {
  int t = 10;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    segtree st1, st2;
    st1.tree = vector<int>(4 * n + 1);
    st2.tree = vector<int>(4 * n + 1);
    int best = 0;
    vector<int> lis(n + 1), lds(n + 1);

    for (int i = 1; i <= n; i++) {
      lis[i] = st1.query(1, 1, n, 1, a[i] - 1) + 1;
      st1.update(1, 1, n, a[i], lis[i]);
      best = max(best, lis[i]);
    }
    for (int i = n; i >= 1; i--) {
      lds[i] = st2.query(1, 1, n, a[i] + 1, n) + 1;
      st2.update(1, 1, n, a[i], lds[i]);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (lis[i] + lds[i] - 1 == best) {
        ans.emplace_back(a[i]);
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << " ";
    cout << '\n';
  }
}
