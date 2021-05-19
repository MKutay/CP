/**
 *  author: MKutayBozkurt
 *  created: 03.04.2021 10:04:24
**/
#include <bits/stdc++.h>
using namespace std;

struct sqrt_decomp {
  int n, k;
  vector<int> next, count, power, start, finish, who;
  void init(vector<int> a, int N) {
    n = N;
    k = sqrt(n);
    next.resize(n);
    count.resize(n);
    start.resize(n);
    finish.resize(n);
    who.resize(n);
    power = a;
    build();
  }
  void build() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (i % k == 0) {
        cnt++;
        start[cnt] = i;
      }
      finish[cnt] = i;
      who[i] = cnt;
    }
    for (int i = 0; i <= cnt; i++) update(i);
  }
  void update(int index) {
    for (int i = finish[index]; i >= start[index]; i--) {
      if (i + power[i] > finish[index]) {
        count[i] = 0;
        next[i] = i;
      } else {
        count[i] = count[i + power[i]] + 1;
        next[i] = next[i + power[i]];
      }
    }
  }
  pair<int, int> query(int index) {
    int next_ans = 0, count_ans = 0;
    while (index < n) {
      count_ans += count[index] + 1;
      index = next[index];
      next_ans = index;
      index += power[index];
    }
    return make_pair(next_ans, count_ans);
  }
};
 
int32_t main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, M; cin >> N >> M;
  vector<int> A(N); for (int &x : A) cin >> x;
 
  sqrt_decomp sd;
  sd.init(A, N);
 
  while (M--) {
    int op; cin >> op;
    if (op) {
      int i; cin >> i, i--;
      auto ans = sd.query(i);
      cout << ans.first + 1 << " " << ans.second << '\n';
    } else {
      int i, j; cin >> i >> j, i--;
      sd.power[i] = j;
      sd.update(sd.who[i]);
    }
  }
}
