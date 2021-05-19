/**
 *  author: MKutayBozkurt
 *  created: 02.03.2021 20:02:29
**/
#include <bits/stdc++.h>
using namespace std;

struct itm {
  int x, y, c;
};

int N, A, B;
vector<string> S;

int sp(int x, int y) {
  vector<vector<int>> vis(N, vector<int>(N));
  bool cmp = (A < B);
  deque<itm> q;
  int ans = 0;
  q.push_front(itm{x, y, 0});
  while (q.size()) {
    itm p = q.front();
    q.pop_front();
    if (p.x < 0 || p.y < 0 || p.x >= N || p.y >= N || vis[p.x][p.y]) continue;
    //cerr << p.x << " " << p.y << " " << p.c << " " << S[p.x][p.y] << " ";
    ans = max(ans, p.c);
    vis[p.x][p.y] = 1;
    if (p.x > 0) {
      if (S[p.x - 1][p.y] == S[p.x][p.y]) {
        if (cmp) q.push_front(itm{p.x - 1, p.y, p.c + A});
        else q.push_back(itm{p.x - 1, p.y, p.c + A});
      } else {
        if (cmp) q.push_back(itm{p.x - 1, p.y, p.c + B});
        else q.push_front(itm{p.x - 1, p.y, p.c + B});
      }
    }
    if (p.x < N - 1) {
      if (S[p.x + 1][p.y] == S[p.x][p.y]) {
        if (cmp) q.push_front(itm{p.x + 1, p.y, p.c + A});
        else q.push_back(itm{p.x + 1, p.y, p.c + A});
      } else {
        if (cmp) q.push_back(itm{p.x + 1, p.y, p.c + B});
        else q.push_front(itm{p.x + 1, p.y, p.c + B});
      }
    }
    if (p.y > 0) {
      if (S[p.x][p.y - 1] == S[p.x][p.y]) {
        if (cmp) q.push_front(itm{p.x, p.y - 1, p.c + A});
        else q.push_back(itm{p.x, p.y - 1, p.c + A});
      } else {
        if (cmp) q.push_back(itm{p.x, p.y - 1, p.c + B});
        else q.push_front(itm{p.x, p.y - 1, p.c + B});
      }
    }
    if (p.y < N - 1) {
      if (S[p.x][p.y] == S[p.x][p.y]) {
        if (cmp) q.push_front(itm{p.x, p.y + 1, p.c + A});
        else q.push_back(itm{p.x, p.y + 1, p.c + A});
      } else {
        if (cmp) q.push_back(itm{p.x, p.y + 1, p.c + B});
        else q.push_front(itm{p.x, p.y + 1, p.c + B});
      }
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen("distant.in", "r", stdin);
  //freopen("distant.out", "w", stdout);
  cin >> N >> A >> B;
  S.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans = max(ans, sp(i, j));
    }
  }

  cout << ans << '\n';
}
