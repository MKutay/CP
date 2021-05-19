/**
 *  author: MKutayBozkurt
 *  created: 24.01.2021 14:37:55
**/
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

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  int odd = 0, even = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] & 1) A[i] = 1, odd++;
    else A[i] = 0, even++;
  }
  int ans = 0;
  int p = 0;
  while (1) {
    assert(even >= 0 && odd >= 0);
    debug() << imie(odd) imie(even);
    if (p == 1) {
      if (odd > 0) {
        ans++;
        odd--;
      } else {
        break;
      }
    } else {
      if (even > 0) {
        ans++;
        even--;
      } else {
        if (odd >= 2) {
          ans++;
          odd -= 2;
        } else if (odd == 1) {
          ans--;
          break;
        } else {
          break;
        }
      }
    }
    p ^= 1;
  }
  cout << ans << '\n';
}
