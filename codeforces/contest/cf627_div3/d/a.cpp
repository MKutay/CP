/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 18:04:10
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
  int N; cin >> N;
  vector<int> A(N), B(N);
  for (int &x : A) cin >> x;
  for (int &x : B) cin >> x;
  vector<int> c(N);
  for (int i = 0; i < N; i++) {
    c[i] = A[i] - B[i];
  }
  sort(c.begin(), c.end());
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (c[i] <= 0) continue;
    auto it = lower_bound(c.begin(), c.end(), 1 - c[i]);
    ans += i - (it - c.begin());
  }
  cout << ans << '\n';
}
