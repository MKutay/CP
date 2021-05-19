#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, K; cin >> N >> K;
  vector<pair<int, int>> A(K);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
}
