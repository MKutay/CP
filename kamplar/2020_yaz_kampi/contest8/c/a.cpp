#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (int i = 0; i < N; i++) {
    pq.push(A[i]);
  }
  if (N % 2 == 0) {
    pq.push(0);
  }
  long long ans = 0;
  while (pq.size() > 1) {
    long long res = 0;
    for (int i = 0; i < 3 && pq.size(); i++) {
      res += pq.top();
      pq.pop();
    }
    ans += res;
    pq.push(res);
  }
  cout << ans << '\n';
}
