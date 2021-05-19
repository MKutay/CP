/**
 *  https://codeforces.com/contest/744/problem/B
 *  author: MKutayBozkurt
 *  created: 27.11.2020 17:05:07
**/
#include <bits/stdc++.h>
using namespace std;

void query(vector<int> a) {
  cout << a.size() << '\n';
  for (int x : a) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  vector<vector<int>> x(N, vector<int>(N)), y(N, vector<int>(N));
  for (int j = 0; (1 << j) < N; j++) {
    vector<int> a, b;
    for (int i = 0; i < N; i++) {
      if (i & (1 << j)) {
        a.emplace_back(i);
      } else {
        b.emplace_back(i);
      }
    }
    query(a);
    for (int i = 0; i < N; i++) {
      cin >> x[i][j];
    }
    query(b);
    for (int i = 0; i < N; i++) {
      cin >> y[i][j];
    }
  }
  cout << "-1\n";
  for (int i = 0; i < N; i++) {
    int ans = 2e9;
    for (int j = 0; (1 << j) < N; j++) {
      if (i & (1 << j)) {
        ans = min(ans, y[i][j]);
      } else {
        ans = min(ans, x[i][j]);
      }
    }
    cout << ans << " ";
  }
  cout << endl;
}
