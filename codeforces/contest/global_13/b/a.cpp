/**
 *  author: MKutayBozkurt
 *  created: 28.02.2021 16:35:14
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, U, V; cin >> N >> U >> V;
  vector<int> A(N); for (int &x : A) cin >> x;
  int mx = 0;
  for (int i = 0; i < N - 1; i++) {
    mx = max(mx, abs(A[i] - A[i + 1]));
  }
  if (mx >= 2) {
    cout << "0\n";
  } else if (mx == 1) {
    cout << min(U, V) << '\n';
  } else {
    cout << V + min(U, V) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) solve();
}
