/**
 *  author: MKutayBozkurt
 *  created: 22.01.2021 21:38:21
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N);
  map<int, int> m;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    m[A[i]]++;
  }
  int mn = 1e9;
  for (int i = 0; i < N; i++) {
    mn = min(m[A[i]], mn);
  }
  if (mn >= 2) {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      if (m[A[i]] > mn) {
        ans += m[A[i]] - mn;
        m[A[i]] = mn;
      }
    }
    cout << ans << '\n';
    return 0;
  }
  if (N < 6) {
    cout << N << '\n';
    return 0;
  }
  vector<int> nx = {4, 8, 15, 16, 23, 42};
  int ind = 0;
  bool flag = 0;
  for (int i = 0; i < N; i++) {
    if (ind == 6) {
      flag = 1;
      break;
    }
    if (A[i] == nx[ind]) {
      ind++;
    }
  }
  if (ind == 6) flag = 1;
  if (flag) {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      if (m[A[i]] > mn) {
        ans += m[A[i]] - mn;
        m[A[i]] = mn;
      }
    }
    cout << ans << '\n';
    return 0;
  }
  cout << N << '\n';
}
