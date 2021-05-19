/**
 *  author: MKutayBozkurt
 *  created: 19.01.2021 17:35:34
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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string S; cin >> S;
    string ans = "1";
    for (int i = 1; i < N; i++) {
      int a = (ans[i - 1] - '0') + (S[i - 1] - '0');
      int b = S[i] - '0';
      if (a == 0) {
        ans += '1';
      } else if (a == 1) {
        if (b == 0) {
          ans += '0';
        } else {
          ans += '1';
        }
      } else {
        if (b == 0) {
          ans += '1';
        } else {
          ans += '0';
        }
      }
    }
    cout << ans << '\n';
  }
}
