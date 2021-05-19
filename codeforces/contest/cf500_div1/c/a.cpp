/**
 *  author: MKutayBozkurt
 *  created: 01.03.2021 20:18:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  int K = (N + 1) / 2;
  int sum = 0;
  for (int i = 1; i <= K; i++) {
    int res = 1e9;
    int ind = -1;
    for (int j = 0; j < N; j++) {
      if (j == 0) {
        int a = A[j + 1] - A[j] + 1;
        if (a < 0) a = 0;
        if (a < res) {
          res = a;
          ind = j;
        }
      } else if (j == N - 1) {
        int a = A[j - 1] - A[j] + 1;
        if (a < 0) a = 0;
        if (a < res) {
          res = a;
          ind = j;
        }
      } else {
        int a = A[j - 1] - A[j] + 1;
        int b = A[j + 1] - A[j] + 1;
        if (a < 0) a = 0;
        if (b < 0) b = 0;
        if (a + b < res) {
          res = a + b;
          ind = j;
        }
      }
    }
    sum += res;
    cout << sum << ' ';
  }
}
