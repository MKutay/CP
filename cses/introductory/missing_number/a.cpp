/**
 *  author: MKutayBozkurt
 *  created: 17.01.2021 21:13:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N - 1); for (int &x : A) cin >> x;
  sort(A.begin(), A.end());
  for (int i = 0; i < N; i++) {
    if (i + 1 != A[i]) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
}
