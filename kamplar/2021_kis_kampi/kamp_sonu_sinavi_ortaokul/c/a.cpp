/**
 *  author: MKutayBozkurt
 *  created: 10.04.2021 09:25:15
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

string S, T; 
int N, M;

const int mod = 1e9 + 7;

int mul(int x, int y) {
  return (x % mod) * (y % mod) % mod;
}

int add(int x, int y) {
  return (x % mod) + (y % mod) % mod;
}

int sub(int x, int y) {
  x = (x % mod) - (y % mod) % mod;
  while (x < 0) {
    x += mod;
  }
  return x;
}

int rabin_karp(string s) {
  string t = T;
  int n = s.size();
  int m = t.size();
  swap(s, t);
  swap(n, m);
  vector<int> power(m + 1);
  for (int i = 0; i <= m; i++) {
    power[i] = (i == 0 ? 1 : mul(power[i - 1], 31));
  }
  int hs = 0, ht = 0;
  for (int i = 0; i < m; i++) {
    hs = mul(hs, 31);
    hs = add(hs, (int) s[i]);

    ht = mul(ht, 31);
    ht = add(ht, (int) t[i]);
  }

  for (int i = m - 1; i < n; i++) {
    if (hs == ht) {
      return 1;
    }
    hs = sub(hs, mul(power[m - 1], s[i - m + 1]));
    hs = mul(hs, 31);
    hs = add(hs, s[i + 1]);
  }
  return 0;
}

int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> S >> T;
  N = S.size();
  M = T.size();

  function<int(int)> check = [&](int ind) {
    string s;
    for (int i = 0; i < ind; i++) {
      s += S[i];
    }
    return rabin_karp(s);
  };

  int l = 0, r = N;
  while (l <= r) {
    debug() << imie(l) imie(r);
    int m = (l + r) / 2;
    if (check(m)) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  debug() << imie(l) imie(r);
  cout << (l + r) / 2ll << '\n';
}
