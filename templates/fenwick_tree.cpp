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
