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

int f1(string S, int A, int B) {
  debug() << imie(S) imie(A) imie(B);
  int N = S.size();
  if (A == 0) {
    char mx = (char) 10;
    char mn = (char) 100;
    for (int i = B + 1; i < N; i++) {
      mx = max(mx, S[i]);
      mn = min(mn, S[i]);
    }
    debug() << imie(mn) imie(mx);
    int ans = 0;
    for (char i = mn; i <= 'Z'; i++) {
      if (i > mx) break;
      if (i == mn) {
        ans++;
        continue;
      }
      vector<int> ind;
      for (int j = B + 1; j < N; j++) {
        if (S[j] >= i) {
          ind.emplace_back(1);
        } else {
          ind.emplace_back(0);
        }
      }
      int j = 0;
      while (j < (int) ind.size()) {
        if (ind[j] == 1) {
          while (j < (int) ind.size() && ind[j] == 1) {
            j++;
          }
          ans++;
        }
        j++;
      }
      debug() << imie(0) imie(i) imie(ind);
    }
    return ans;
  } else {
    char mx = (char) 10;
    char mn = (char) 100;
    for (int i = 0; i < A; i++) {
      mx = max(mx, S[i]);
      mn = min(mn, S[i]);
    }
    debug() << imie(mn) imie(mx);
    int ans = 0;
    for (char i = mn; i <= 'Z'; i++) {
      if (i > mx) break;
      if (i == mn) {
        ans++;
        continue;
      }
      vector<int> ind;
      for (int j = 0; j < A; j++) {
        if (S[j] >= i) {
          ind.emplace_back(1);
        } else {
          ind.emplace_back(0);
        }
      }
      int j = 0;
      while (j < (int) ind.size()) {
        if (ind[j] == 1) {
          while (j < (int) ind.size() && ind[j] == 1) {
            j++;
          }
          ans++;
        }
        j++;
      }
      debug() << imie(1) imie(i) imie(ind);
    }
    return ans;
  }
  return -1;
}

int f2(string S, int A, int B) {
  int N = S.size();
  int a = f1(S, A, N - 1);
  int b = f1(S, 0, B);
  debug() << imie(a) imie(b);
  return a + b;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q; cin >> N >> Q;
  string S; cin >> S;
  while (Q--) {
    int A, B; cin >> A >> B, A--, B--;
    if (A == 0 || B == N - 1) {
      cout << f1(S, A, B) << '\n';
    } else {
      cout << f2(S, A, B) << '\n';
    }
  }
}
