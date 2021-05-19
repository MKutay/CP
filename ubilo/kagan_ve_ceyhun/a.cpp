#include <bits/stdc++.h>
using namespace std;

struct itm {
  int i, I, x;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("kvec.gir", "r", stdin);
  freopen("kvec.cik", "w", stdout);
  int N, T; cin >> N >> T;
  string S; cin >> S;
  vector<int> A(N + 1);
  for (int i = 0; i < N; i++) A[i] = S[i] - '0';

  vector<int> cnt(2);
  for (char c : S) cnt[c - '0']++;

  vector<vector<itm>> g(T + 1);

  for (int i = 0; i < T; i++) {
    int C, I, X; cin >> C >> I >> X; I--;
    g[C].emplace_back(itm{i + 1, I, X});
  }

  vector<int> res(T + 5);

  function<void(int)> dfs = [&](int node) {
    if (cnt[0] == cnt[1]) {
      res[node] = 1;
    }
    for (auto other_node : g[node]) {
      cnt[A[other_node.I]]--;
      swap(other_node.x, A[other_node.I]);
      cnt[A[other_node.I]]++;

      dfs(other_node.i);

      cnt[A[other_node.I]]--;
      swap(other_node.x, A[other_node.I]);
      cnt[A[other_node.I]]++;
    }
  };

  dfs(0);

  for (int i = 1; i <= T; i++) cout << (res[i] == 1 ? "EVET" : "HAYIR") << '\n';
}
