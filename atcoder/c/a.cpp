#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long n; cin >> n;
  long long a = sqrt(n) + 1;
  vector<long long> s;
  for (long long i = 1; i <= a; i++) {
    if (n % i == 0) {
      s.emplace_back(i);
      s.emplace_back(n / i);
    }
  }
  for (int x : s) cout << x << '\n';
}
