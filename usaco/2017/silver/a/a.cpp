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

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen("homework.in", "r", stdin);
  //freopen("homework.out", "w", stdout);
  int N; cin >> N;
  vector<int> A(N); for (int &x : A) cin >> x;
  multiset<int> s;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i];
    s.insert(A[i]);
  }

  debug() << imie(sum) imie(s);

  vector<pair<double, int>> a;

  for (int i = 0; i <= N - 2; i++) {
    sum -= A[i];
    s.erase(s.find(A[i]));
    int mn = *s.begin();
    double med;
    if (i == N - 2) med = (double) (sum - mn) / (N - i - 1);
    else med = (double) (sum - mn) / (N - i - 2);
    a.emplace_back(med, i);
    debug() << imie(s) imie(sum) imie(med) imie(mn);
  }

  sort(a.begin(), a.end());
  double mx = a.back().first;
  debug() << imie(a);
  for (auto x : a) {
    if (x.first == mx) {
      cout << x.second + 1 << '\n';
    }
  }
}
