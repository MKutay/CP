/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 13:28:54
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
  vector<int> A(1 << N); for (int &x : A) cin >> x;
  vector<vector<int>> a(N + 5);
  a[0] = A;
  for (int i = 1; i <= N; i++) {
    debug() << imie(i);
    for (int j = 0; j < (int) a[i - 1].size(); j += 2) {
      debug() << imie(a[i]) imie(a[i - 1]) imie(j);
      a[i].emplace_back(max(a[i - 1][j], a[i - 1][j + 1]));
    }
  }
  debug() << imie(a);
  int ans = min(a[N - 1][0], a[N - 1][1]);
  int ind = -1;
  for (int i = 0; i < (1 << N); i++) {
    if (A[i] == ans) ind = i;
  }
  cout << ind + 1 << '\n';
}
