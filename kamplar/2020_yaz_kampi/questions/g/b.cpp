#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

vector<int> tree, a;

void build(int node, int l, int r) {
  if (l == r) {
    tree[node] = a[l];
    return;
  }
  int m = (l + r) / 2;
  build(node * 2, l, m);
  build(node * 2 + 1, m + 1, r);
  tree[node] = tree[node * 2] & tree[node * 2 + 1];
}

int query(int node, int l, int r, int xl, int xr) {
  if (l > r || l > xr || r < xl) return INT_MAX;
  if (l >= xl && r <= xr) return tree[node];
  int m = (l + r) / 2;
  int L = query(node * 2, l, m, xl, xr);
  int R = query(node * 2 + 1, m + 1, r, xl, xr);
  return (L & R);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    a = vector<int>(4 * N + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[n + i] = a[i];
      a[2 * n + i] = a[i];
      a[3 * n + i] = a[i];
    }
    tree = vector<int>(4 * N + 1);
    build(1, 1, 4 * n);
    for (int i = 1; i <= n; i++) {
      cout << query(1, 1, 4 * n, max(1, n + i - k), min(4 * n, n + i + k)) << " ";
    }
    cout << '\n';
  }
}
