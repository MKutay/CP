/**
 *  author: MKutayBozkurt
 *  created: 19.12.2020 08:09:03
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

struct item {
  int t, x, y;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, T; cin >> N >> T;
  string S; cin >> S;
  vector<item> A(T);
  for (int i = 0; i < T; i++) {
    cin >> A[i].t >> A[i].x >> A[i].y;
  }
  sort(A.begin(), A.end(), [&](item &a, item&b) {
    return a.t < b.t;
  });
  for (auto x : A) {
    cerr << x.t << " " << x.x << " " << x.y << '\n';
  }
}
