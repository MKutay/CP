/**
 *  author: MKutayBozkurt
 *  created: 04.03.2021 19:37:18
**/
#include <bits/stdc++.h>
using namespace std;

template<typename T, typename F = function<T(const T&, const T&)>> class sparsetable {
  public:
    int N, K;
    vector<vector<T>> table;
    F f;
    sparsetable() {}
    sparsetable(vector<T> &A, F _f) : f(_f) {
      N = (int) A.size();
      K = 32 - __builtin_clz(N);
      table.resize(K);
      table[0] = A;
      for (int i = 1; i < K; i++) {
        table[i].resize(N - (1 << i) + 1);
        for (int j = 0; j < (int) table[i].size(); j++) {
          table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
      }
    }
    T query(int l, int r) {
      int j = 31 - __builtin_clz(r - l + 1);
      return f(table[j][l], table[j][r - (1 << j) + 1]);
    }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  map<int, int> m;
  for (int i = 0; i < N; i++) m[A[i]]++;
  sparsetable st(A, [&](int a, int b) {
    return gcd(a, b);
  });
  sparsetable st2(A, [&](int a, int b) {
    return min(a, b);
  });
  int M; cin >> M;
  while (M--) {
    int l, r; cin >> l >> r, l--, r--;
    int x = st.query(l, r);
    int y = st2.query(l, r);
    cerr << x << " " << y << " ";
    if (x == y) {
      cout << r - l + 1 - m[x] << '\n';
    } else {
      cout << r - l + 1 << '\n';
    }
  }
}
