#include "bits/stdc++.h"
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

int n;
vector<int> a;
vector<vector<int>> dp;
int us;

int f(int x, int y) {
  int ret;
  if (dp[x][y] != -1) return dp[x][y];
  if (x == 1) ret = a[y];
  else ret = min(f(x - 1, y), f(x - 1, y - 1)) + a[y];
  debug() << imie(x) imie(y) imie(ret);
  us++;
  return dp[x][y] = ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  a = vector<int>(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
  f(n, n);
  debug() << imie(us);
  int q; cin >> q;
  while (q--) {
    int x, y; cin >> x >> y;
    if (dp[x][y] != -1) {
      cout << dp[x][y] << '\n';
    } else {
      assert(0);
    }
  }
}
