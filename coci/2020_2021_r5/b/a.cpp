#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  int ans = 0;
  stack<int> s;
  for (int i = 0; i < N; i++) {
    while (s.size() && s.top() > A[i]) {
      s.pop();
    }
    if (s.size() && s.top() == A[i]) {
      continue;
    }
    if (A[i] != 0) {
      ans++;
      s.push(A[i]);
    }
  }
  cout << ans << '\n';
}
