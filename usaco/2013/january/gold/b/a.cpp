/**
 *  author: MKutayBozkurt
 *  created: 09.05.2021 20:26:17
**/
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max();

struct coord {
  int x, y;
};

int32_t main() {
  freopen("island.in", "r", stdin);
  freopen("island.out", "w", stdout);
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M; cin >> N >> M;
  vector<vector<char>> A(N, vector<char>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }

  vector<int> dX = {-1, 1, 0, 0};
  vector<int> dY = {0, 0, -1, 1};

  // find islands
  vector<coord> islands;
  vector<vector<int>> island_ind(N, vector<int>(M, -1));
  {
    vector<vector<int>> vis(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (A[i][j] != 'X' || vis[i][j]) {
          continue;
        }

        queue<coord> next;
        next.push(coord{i, j});

        while (next.size()) {
          auto cur = next.front();
          next.pop();

          if (cur.x < 0 || cur.y < 0 || cur.x >= N || cur.y >= M || vis[cur.x][cur.y] || A[cur.x][cur.y] != 'X') {
            continue;
          }

          vis[cur.x][cur.y] = true;
          for (int d = 0; d < 4; ++d) {
            coord new_ = {cur.x + dX[d], cur.y + dY[d]};

            next.emplace(new_);
          }
        }

        islands.push_back(coord{i, j});
        island_ind[i][j] = (int) islands.size() - 1;
      }
    }
  }

  assert(islands.size() <= 16);

  // find the distance between islands
  const int K = islands.size();
  vector<vector<int>> mat(K, vector<int>(K, (int) INF)); // adj matrix

  {
    for (auto source : islands) {
      vector<vector<int>> vis(N, vector<int>(M));
      deque<pair<coord, int>> q;
      q.push_front({source, 0});

      while (q.size()) {
        coord crd = q.front().first;
        int dist = q.front().second;
        q.pop_front();

        if (vis[crd.x][crd.y]) continue;
        else if (island_ind[crd.x][crd.y] != -1) {
          mat[island_ind[source.x][source.y]][island_ind[crd.x][crd.y]] = dist;
        }

        vis[crd.x][crd.y] = 1;

        for (int i = 0; i < 4; i++) {
          coord new_coord = coord{crd.x + dX[i], crd.y + dY[i]};

          if (new_coord.x < 0 || new_coord.x >= N || new_coord.y < 0 || new_coord.y >= M || A[new_coord.x][new_coord.y] == '.') {
            continue;
          } else if (A[new_coord.x][new_coord.y] == 'X') {
            q.push_front({new_coord, dist});
          } else {
            q.push_back({new_coord, dist + 1});
          }
        }
      }
    }
  }

  // solve it using TSP
  long long ans = INF;
  {
    vector<vector<long long>> dp(K, vector<long long>((1 << K), INF));
    
    vector<pair<int, int>> masks;
    for (int mask = 0; mask < (1 << K); mask++) {
      masks.emplace_back(__builtin_popcount(mask), mask);
    }

    sort(masks.begin(), masks.end());

    for (auto [size, mask] : masks) {
      vector<int> vis;
      bitset<15> bs(mask);
      for (int i = 0; i < K; i++) {
        if (bs[i]) {
          vis.emplace_back(i);
        }
      }

      if (size == 1) {
        dp[vis.front()][mask] = 0;
        continue;
      }

      for (int x : vis) {
        for (int y : vis) {
          if (x == y) continue;
          bs[x] = false;
          dp[x][mask] = min(dp[x][mask], dp[y][bs.to_ulong()] + mat[x][y]);
          bs[x] = true;
        }

        if (size == K) {
          ans = min(ans, dp[x][mask]);
        }
      }
    }
  }

  cout << ans * (ans < INF) << '\n';
}
