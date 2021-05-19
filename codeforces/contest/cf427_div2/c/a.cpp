/**
 *  author: MKutayBozkurt
 *  created: 15.02.2021 21:20:30
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

struct item1 {
  int x, y, s;
};

struct item2 {
  int t, x1, y1, x2, y2;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, Q, C; cin >> N >> Q >> C;
  vector<item1> A(N);
  vector<vector<vector<int>>> cnt(105, vector<vector<int>>(105, vector<int>(C + 5)));
  for (int i = 0; i < N; i++) {
    cin >> A[i].x >> A[i].y >> A[i].s;
    cnt[A[i].x][A[i].y][A[i].s]++;
  }
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int c = 0; c <= C; c++) {
        cnt[i][j][c] += cnt[i - 1][j][c] + cnt[i][j - 1][c] - cnt[i - 1][j - 1][c];
      }
    }
  }

  while (Q--) {
    int T, X1, Y1, X2, Y2; cin >> T >> X1 >> Y1 >> X2 >> Y2;
    int res = 0;
    for (int c = 0; c <= C; c++) {
      int a = (T + c) % (C + 1);
      res += a * (cnt[X2][Y2][c] - cnt[X1 - 1][Y2][c] - cnt[X2][Y1 - 1][c] + cnt[X1 - 1][Y1 - 1][c]);
    }
    cout << res << '\n';
  }
}
