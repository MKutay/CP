/**
 *  author: MKutayBozkurt
 *  created: 06.03.2021 11:30:36
**/
#include <bits/stdc++.h>
using namespace std;

struct itm {
  int x, d;
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("paint.in", "r", stdin);
  freopen("paint.out", "w", stdout);
  int N, K; cin >> N >> K;
  vector<itm> a(N * 2);
  int x = 0;
  for (int i = 0; i < N; i++) {
    int d; cin >> d;
    char c; cin >> c;
    int x1 = x + d * (c == 'R' ? 1 : -1);

    a[2 * i].x = min(x, x1);
    a[2 * i].d = 1;
    a[2 * i + 1].x = max(x, x1);
    a[2 * i + 1].d = -1;
    x = x1;
  }
  sort(a.begin(), a.end(), [&](const itm a, const itm b) {
    return a.x < b.x;
  });
  int ans = 0;
  int c = 0;
  for (int i = 0; i < 2 * N; i++) {
    if (i > 0 && c >= K) {
      ans += a[i].x - a[i - 1].x;
    }
    c += a[i].d;
  }
  cout << ans << '\n';
}
