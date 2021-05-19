/**
 *  author: MKutayBozkurt
 *  created: 26.12.2020 17:48:59
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    vector<int> A(4); for (int &x : A) cin >> x;
    sort(A.begin(), A.end());
    cout << A[0] * A[2] << '\n';
  }
}
