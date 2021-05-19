#include <bits/stdc++.h>
using namespace std;

int is_prime(long long N) {
  long long a = sqrt(N);
  for (int i = 2; i <= a + 1; i++) {
    if (N % i == 0) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("magicdiamonds.gir", "r", stdin);
  freopen("magicdiamonds.cik", "w", stdout);
  long long N; cin >> N;
  if (N == 3) cout << "3\n";
  else if (N == 2) cout << "2\n";
  else if (N == 1) cout << "1\n";
  else cout << (is_prime(N) ? 2 : 1) << '\n';
}
