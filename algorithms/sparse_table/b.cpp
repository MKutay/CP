#include <bits/stdc++.h>
using namespace std;

struct sparse_table {
  vector<vector<int>> table;
  int N, K;

  int f(int a, int b) {
    return min(a, b);
  }

  void init(int n) {
    N = n;
    K = log2(n) + 2;
    table = vector<vector<int>>(n, vector<int>(K));
  }
  void build(vector<int> A) {
    for (int i = 0; i < N; i++) {
      table[i][0] = A[i];
    }
    for (int j = 1; j <= K; j++) {
      for (int i = 0; i + (1 << j) <= N; i++) {
        table[i][j] = f(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  int query(int l, int r) {
    long long sum = 0;
    for (int j = K; j >= 0; j--) {
      if ((1 << j) <= r - l + 1) {
        sum += table[l][j];
        l += 1 << j;
      }
    }
    return sum;
  }

  int rmq(int l, int r) {
    int j = 31 - __builtin_clz(r - l + 1);
    return f(table[l][j], table[r - (1 << j) + 1][j]);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sparse_table st;
  st.init(N);
  st.build(A);
  int m; cin >> m;
  while (m--) {
    int l, r; cin >> l >> r;
    cout << st.rmq(l, r) << '\n';
  }
}
