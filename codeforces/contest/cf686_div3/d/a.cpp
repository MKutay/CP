#include <bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << (it == d.b ? "" : ", ") << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define int long long

int fpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}


double log(int a, int b) {
  return log(a) / log(b);
}

void solve() {
  int n; cin >> n;
  vector<int> div;
  int a = sqrtl(n) + 1;
  for (int i = 2; i <= a; i++) {
    if (n % i == 0) {
      div.emplace_back(i);
    }
  }
  int ans = INT_MIN;
  int ans2 = 0;
  for (int x : div) {
    int n2 = n;
    int res = 0;
    while (n2 % x == 0) n2 /= x, res++;
    debug() << imie(x) imie(res);
    if (res > ans) {
      ans = res;
      ans2 = x;
    }
  }
  if (ans == INT_MIN) {
    cout << "1\n" << n << '\n';
    return;
  }
  cout << ans << '\n';
  int p = 1;
  for (int i = 0; i < ans - 1; i++) {
    cout << ans2 << " ";
    p *= ans2;
  }
  cout << n / p << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    solve();
  }
}
