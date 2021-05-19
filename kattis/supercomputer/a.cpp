#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class Bit {
  public:
  vector<T> tree;
  F cal;
  int sz;
  int lb(int x) { return x & -x; }
  void update(int ind, T val) {
    //++ind;
    while (ind <= sz) {
      tree[ind] = cal(tree[ind], val);
      ind += lb(ind);
    }
  }
  Bit(vector<T> v, T uneff, F _cal) : cal(_cal) {
    sz = (int) v.size() + 1;
    tree.resize(sz, uneff);
    for (int i = 0; i < (int) v.size(); ++i) update(i, v[i]);
  }
  T sum(int ind) {
    //++ind;
    T res = 0;
    while (ind) {
      res = cal(res, tree[ind]);
      ind -= lb(ind);
    }
    return res;
  }
  T rangeSum(int i, int j) {
    return sum(j) - (i == 0 ? 0 : sum(i));
  }
  void clear() {
    fill(tree.begin(), tree.end(), tree[0]);
  }
};

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  int q; cin >> q;
  Bit ft(vector<int>(n, 0), 0, [&](int a, int b) {
    return a + b;
  });
  while (q--) {
    char op; cin >> op;
    if (op == 'F') {
      int i; cin >> i, i--;
      cout << i << " " << ft.rangeSum(i, i) << '\n';
      if (ft.rangeSum(i, i) == 1) ft.update(i, -1);
      else ft.update(i, 1);
      cout << i << " " << ft.rangeSum(i, i) << '\n';
    } else {
      int i, j; cin >> i >> j, i--, j--;
      cout << i << " " << j << " ";
      cout << ft.rangeSum(i, j) << '\n';
    }
  }
  return 0;
}

