/**
 *  author: MKutayBozkurt
 *  created: 10.05.2021 21:05:57
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
  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);
  int N; cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) cin >> A[i];
  vector<int> sum(N + 1), mn(N + 1);
  int best_num, best_den;

  sum[N] = A[N];
  mn[N] = A[N];
  
  for (int i = N - 1; i >= 1; i--) {
    sum[i] = sum[i + 1] + A[i];
    mn[i] = min(mn[i + 1], A[i]);
  }

  best_num = 0;
  best_den = 1;

  for (int i = 1; i <= N - 2; i++) {
    if ((sum[i + 1] - mn[i + 1]) * best_den > best_num * (N - i - 1)) {
      best_num = sum[i + 1] - mn[i + 1];
      best_den = N - i - 1;
    }
  }

  for (int i = 1; i <= N - 2; i++) {
    if ((sum[i + 1] - mn[i + 1]) * best_den == best_num * (N - i - 1)) {
      cout << i << '\n';
    }
  }
}

