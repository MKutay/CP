/**
 *  author: MKutayBozkurt
 *  created: 01.02.2021 09:10:48
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, D; cin >> N >> D;
    vector<int> A(N); for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    if (A.back() <= D || A[0] + A[1] <= D) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
