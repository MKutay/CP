#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  long long a1 = 0, a3 = INT_MIN;
  double a2 = 0;
  for (int i = 0; i < n; i++) {
    a1 += abs(a[i]);
    a3 = max(a3, (long long) abs(a[i]));
    a2 += a[i] * (long long) a[i];
  }
  cout << fixed << setprecision(10) << a1 << '\n' << (double) sqrt((double) a2) << '\n' << a3 << '\n';
}
