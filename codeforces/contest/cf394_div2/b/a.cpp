/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 13:06:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, L; cin >> N >> L;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> B[i];
  vector<int> a, b;
  for (int i = 1; i < N; i++) {
    a.emplace_back(A[i] - A[i - 1]);
    b.emplace_back(B[i] - B[i - 1]);
  }
  a.emplace_back(L - A.back() + A[0]);
  b.emplace_back(L - B.back() + B[0]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      vector<int> c = b;
      rotate(c.begin(), c.begin() + i, c.end());
      if (c == a) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
