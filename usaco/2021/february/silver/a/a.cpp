/**
 *  author: MKutayBozkurt
 *  created: 28.02.2021 13:14:08
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
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  vector<int> dx = {-1, +1, 0, 0}, dy = {0, 0, -1, +1};
  vector<vector<int>> c(N + 10, vector<int>(N + 10)), d1(N + 10, vector<int>(N + 10)), d2(N + 10, vector<int>(N + 10));
  // c = dolu mu bos mu, 2 ise fazladandir
  // d1 = o cord'un kac tane dolu komsusu var
  // d2 = o cord'un kac tane sahte komsusu var
  for (int i = 0; i < N; i++) {
    int x = A[i].first + 5, y = A[i].second + 5;
    int ans = 0;
    c[x][y] = 1;
    for (int xx : dx) {
      for (int yy : dy) {
        d1[x + xx][y + yy]++;
      }
    }

    d2 = d1;
    queue<pair<int, int>> q;
    q.emplace(x, y);
    vector<vector<int>> vis(N + 10, vector<int>(N + 10));
    while (q.size()) {
      int x2 = q.front().first, y2 = q.front().second;
      q.pop();
      if (x2 <= 0 || y2 <= 0 || x2 >= N + 5 || y2 >= N + 5 || vis[x2][y2]) continue;
      debug() << imie(x2) imie(y2);
      vis[x2][y2] = 1;
      for (int xx : dx) {
        for (int yy : dy) {
          if (d2[x2 + xx][y2 + yy] == 3) {
            int bx = -1, by = -1;
            for (int xx2 : dx) {
              for (int yy2 : dy) {
                if (c[x2 + xx + xx2][y2 + yy + yy2] == 0) {
                  bx = x2 + xx + xx2;
                  by = y2 + yy + yy2;
                }
              }
            }
            for (int xx2 : dx) {
              for (int yy2 : dy) {
                d2[bx + xx2][by + yy2]++;
              }
            }
            q.emplace(bx, by);
            ans++;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
