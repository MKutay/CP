/**
 *  author: MKutayBozkurt
 *  created: 02.03.2021 20:02:29
**/
#include <bits/stdc++.h>
using namespace std;

int N, A, B;
vector<string> S;

struct itm {
  int x, y, c;
  bool operator<(itm const &node) const {
    return c > node.c;
  }
};

vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};

int sp(int x, int y) {
  vector<vector<int>> vis(N, vector<int>(N));
  int ans = 0;
  priority_queue<itm> pq;
  pq.push(itm{x, y, 0});
  while (pq.size()) {
    itm p = pq.top();
    pq.pop();
    if (vis[p.x][p.y]) continue;
    vis[p.x][p.y] = 1;
    for (int i = 0; i < 4; i++) {
      int x1 = p.x + dx[i];
      int y1 = p.y + dy[i];
      if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < N) {
        int c = p.c + (S[p.x][p.y] == S[x1][y1] ? A : B);
        pq.push(itm{x1, y1, c});
      }
    }
    ans = max(ans, p.c);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("distant.in", "r", stdin);
  freopen("distant.out", "w", stdout);
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
