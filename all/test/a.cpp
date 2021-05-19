#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  vector<string> a(N);
  for (int i = 0; i < N; i++) {
    a[i] = to_string(A[i]);
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < N; i++) {
    cout << a[i];
  }
}
