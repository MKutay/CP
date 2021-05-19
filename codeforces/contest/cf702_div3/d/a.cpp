/**
 *  author: MKutayBozkurt
 *  created: 16.02.2021 17:35:17
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

vector<int> ans, A;

struct item {
  int x, i;
};

void f(int l, int r, int d) {
  debug() << imie(l) imie(r) imie(d);
  if (r <= l) return;
  if (r - l == 1) {
    ans[l] = d + 1;
    return;
  }
  item mx = item{0, 0};
  for (int i = l; i < r; i++) {
    if (A[i] > mx.x) {
      mx.x = A[i];
      mx.i = i;
    }
  }
  ans[mx.i] = d + 1;
  f(l, mx.i, d + 1);
  f(mx.i + 1, r, d + 1);
}

void solve() {
  int N; cin >> N;
  ans = vector<int>(N + 5);
  A = vector<int>(N); for (int &x : A) cin >> x;
  item mx = item{0, 0};
  for (int i = 0; i < N; i++) {
    if (A[i] > mx.x) {
      mx.x = A[i];
      mx.i = i;
    }
  }
  ans[mx.i] = 0;
  f(0, mx.i, 0);
  f(mx.i + 1, N, 0);
  for (int i = 0; i < N; i++) cout << ans[i] << " ";
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) solve();
}
