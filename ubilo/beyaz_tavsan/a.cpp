#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  // histogram
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("tavsan.gir", "r", stdin);
  freopen("tavsan.cik", "w", stdout);
  int N; cin >> N;
  vector<int> A(N + 1);
  for (int i = 0; i < N; i++) cin >> A[i];
  stack<int> s;
  int ans = 0;
  for (int i = 0; i <= N; i++) {
    while (s.size() && A[i] <= A[s.top()]) {
      int a = A[s.top()];
      s.pop();
      int l = (s.size() ? s.top() : -1);
      ans = max(ans, (i - l - 1) * a);
    }
    s.push(i);
  }
  cout << ans << '\n';
}
