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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string c, d; cin >> c >> d;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      a[i] = c[i] - 'a' + 1;
      b[i] = d[i] - 'a' + 1;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
      cout << "YES\n";
      continue;
    }
    vector<pair<int, int>> m1(27), m2(27);
    for (int i = 0; i < n; i++) {
      int x = m1[a[i]].first, y = m2[b[i]].first;
      x++;
      y++;
      m1[a[i]] = {x, a[i]};
      m2[b[i]] = {y, b[i]};
    }
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    bool flag = 1;
    for (int i = 1; i <= 26; i++) {
      if (m1[i].second == m2[i].second) continue;
      if (m1[i].first == m2[i].first && m1[i].second <= m2[i].second && m1[i].first % k == 0) {
      } else {
        flag = 0;
      }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
  }
}
