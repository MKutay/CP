// https://www.youtube.com/watch?v=kPaJfAUwViY

#include <bits/stdc++.h>
using namespace std;

template<typename T> class fenwickTree {
  public:
    vector<T> table;
    int n;
    fenwickTree(vector<T> a) {
      n = a.size() + 1;
      table.resize(n);
      for (int i = 0; i < (int) a.size(); i++) update(i + 1, a[i]);
    }
    void update(int i, T delta) {
      while (i < n) {
        table[i] += delta;
        i += i & (-i);
      }
    }
    T query(int i) {
      T v{};
      while (i > 0) {
        v += table[i];
        i -= i & (-i);
      }
      return v;
    }
    int range_query(int l, int r) {
      return query(r) - query(l - 1);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int q; cin >> q;
  fenwickTree ft(a);
  while (q--) {
    int op; cin >> op;
    if (op == 1) {
      int i, d; cin >> i >> d;
      ft.update(i, d);
    } else {
      int i, j; cin >> i >> j;
      cout << ft.range_query(i, j) << '\n';
    }
  }
  return 0;
}
