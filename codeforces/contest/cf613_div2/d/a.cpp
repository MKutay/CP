/**
 *  author: MKutayBozkurt
 *  created: 25.02.2021 19:06:25
**/
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int b) {
  if (b < 0) return 0;
  vector<int> l, r;
  for (int i = 0; i < a.size(); i++) {
    if (((a[i] >> b) & 1) == 0) l.emplace_back(a[i]);
    else r.emplace_back(a[i]);
  }
  if (l.size() == 0) return solve(r, b - 1);
  if (r.size() == 0) return solve(l, b - 1);
  return min(solve(l, b - 1), solve(r, b - 1)) + (1 << b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  cout << solve(A, 30);
}
