/**
 *  author: MKutayBozkurt
 *  created: 15.02.2021 21:14:46
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

long long const mod = 1e9 + 7;

long long fpow(int a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a % mod;
      ans %= mod;
		}
		a *= a % mod;
    a %= mod;
		b >>= 1;
    b %= mod;
	}
	return ans % mod;
}


int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int A, B; cin >> A >> B;
    cout << fpow(A, B) % mod << '\n';
  }
}
