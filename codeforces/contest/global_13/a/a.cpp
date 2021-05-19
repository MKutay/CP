/**
 *  author: MKutayBozkurt
 *  created: 28.02.2021 16:35:14
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q; cin >> N >> Q;
  vector<int> A(N); for (int &x : A) cin >> x;
  int one = accumulate(A.begin(), A.end(), 0);
  int zero = N - one;
  while (Q--) {
    int op; cin >> op;
    if (op == 1) {
      int X; cin >> X, X--;
      if (A[X] == 0) {
        A[X] = 1;
        one++;
        zero--;
      } else {
        A[X] = 0;
        one--;
        zero++;
      }
    } else {
      int K; cin >> K;
      if (one >= K) {
        cout << "1\n";
      } else {
        cout << "0\n";
      }
    }
  }
}
