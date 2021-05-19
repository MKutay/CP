#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, X; cin >> N >> X;
    vector<int> A(N); for (int &x : A) cin >> x;
    int x = 0, y = 0;
    for (int i = 0; i < N; i++) {
      x += (A[i] + X - 1) / X;
      y += A[i];
    }
    y = (y + X - 1) / X;
    cout << y << " " << x << '\n';
  }
}
