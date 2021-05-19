#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int n, d;
vector<vector<int>> a;
vector<int> depth;
vector<vector<int>> par;

int walk(int i, int k) {
  for (int j = 0; j <= d && i != -1; j++) {
    if ((1 << j) & k) {
      i = par[j][i];
    }
  }
  return i;
}

int lca(int i, int j) {
  if (depth[i] > depth[j]) {
    i = walk(i, depth[i] - depth[j]);
  }
  if (depth[j] > depth[i]) {
    j = walk(j, depth[j] - depth[i]);
  }

  if (i == j) {
    return i;
  }

  for (int k = d; k >= 0; k--) {
    if (par[k][i] != par[k][j]) {
      i = par[d][i];
      j = par[d][j];
    }
  }

  return par[0][i];
}

int dist(int i, int j) {
  return depth[i] + depth[j] - 2 * depth[lca(i, j)];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  a = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y, x--, y--;
    a[x].emplace_back(y);
    a[y].emplace_back(x);
  }

  d = log2(n);
  par = vector<vector<int>>(d + 1, vector<int>(n, -1));
  depth = vector<int>(n);
  
  queue<int> q;
  vector<int> vis(n);
  q.emplace(0);
  vis[0] = 1;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (auto node : a[x]) if (!vis[node]) {
      vis[node] = 1;
      q.emplace(node);
      par[0][node] = x;
      depth[node] = depth[x] + 1;
    }
  }
  
  for (int k = 1; k <= d; k++) {
    for (int i = 0; i < n; i++) {
      int m = par[k - 1][i];
      if (m != -1) {
        par[k][i] = par[k - 1][m];
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      ans = dist(i - 1, j - 1) + 1;
    }
  }
  cout << ans << '\n';
}

