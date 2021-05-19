#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 10;
const int mxT = 1 << 20;

int N, M;
vector<int> tree;
vector<int> A, B, diff;

void update(int l, int r, int val, int node, int lx, int rx) {
  if (l <= lx && r >= rx) {
    tree[node] = val;
    return;
  }
  int m = (lx + rx) / 2;
  if (l < m) update(l, r, val, 2 * node, lx, m);
  if (r > m) update(l, r, val, 2 * node + 1, m, rx);
}

int query(int x) {
  x += mxT;
  int ans = 0;
  while (1) {
    ans = max(ans, tree[x]);
    x /= 2;
    if (x == 0) return ans;
  }
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N >> M;
  A = vector<int>(mxN);
  B = vector<int>(mxN);
  diff = vector<int>(mxN);
  tree = vector<int>(2 * mxT);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  for (int i = 0; i < M; i++) {
    int O; cin >> O;
    if (O == 1) {
      int X, Y, K; cin >> X >> Y >> K;
      update(Y - 1, Y - 1 + K, i + 1, 1, 0, mxT);
      diff[i + 1] = X - Y;
    } else {
      int X; cin >> X, X--;
      int temp = query(X);
      if (temp == 0) {
        cout << B[X] << '\n';
      } else {
        cout << A[X + diff[temp]] << '\n';
      }
    }
  }
}
