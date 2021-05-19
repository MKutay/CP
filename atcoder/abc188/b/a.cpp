/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 13:28:54
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  vector<int> B(N); for (int &x : B) cin >> x;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += A[i] * B[i];
  }
  if (ans == 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
