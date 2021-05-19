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


void solve() {
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  map<int, vector<int>> m;
  for (int i = 0; i < n; i++) {
    if (m[a[i]].size() == 0) {
      m[a[i]].emplace_back(i);
    } else if (m[a[i]].size() > 0 && a[i] != a[i - 1]) {
      m[a[i]].emplace_back(i);
    }
  }
  int ans = INT_MAX;
  for (auto [y, x] : m) {
    int res = x.size() + 1;
    if (a[0] == y) res--;
    if (a[n - 1] == y) res--;
    ans = min(ans, res);
  }
  debug() << imie(m);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) solve();
}
