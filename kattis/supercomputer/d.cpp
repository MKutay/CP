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
        i += i & -i;
      }
    }
    T query(int i) {
      T v{};
      while (i > 0) {
        v += table[i];
        i -= i & -i;
      }
      return v;
    }
    T range_query(int l, int r) {
      return query(r) - query(l - 1);
    }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, K; cin >> N >> K;
  vector<int> a(N, 0);
  fenwickTree<int> ft(a);
  while (K--) {
    char op; cin >> op;
    if (op == 'F') {
      int i; cin >> i;
      if (ft.range_query(i, i)) ft.update(i, -1);
      else ft.update(i, 1);
    } else {
      int l, r; cin >> l >> r;
      cout << ft.range_query(l, r) << '\n';
    }
  }
}
