#include <bits/stdc++.h>
using namespace std;

struct fenwickTree {
  vector<int> table;
  int n;

  void update(int i, int delta) {
    while (i <= n) {
      table[i] += delta;
      i += i & -i;
    }
  }

  int sum(int i) {
    int s = 0;
    while (i > 0) {
      s += table[i];
      i -= i & -i;
    }
    return s;
  }

  int rangeSum(int i, int j) {
    return sum(j) - (i == 0 ? 0 : sum(i - 1));
  }
};

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int q; cin >> q;
  fenwickTree ft;
  ft.n = n + 1;
  ft.table = vector<int>(n + 1, 0);
  while (q--) {
    char op; cin >> op;
    if (op == 'F') {
      int i; cin >> i;
      if (ft.rangeSum(i, i) == 1) ft.update(i, -1);
      else ft.update(i, 1);
    } else {
      int i, j; cin >> i >> j;
      cout << ft.rangeSum(i, j) << '\n';
    }
  }
  return 0;
}
