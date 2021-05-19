/**
 *  author: MKutayBozkurt
 *  created: 21.01.2021 17:35:23
**/
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> v;
vector<int> C, P;
int root = -1;
vector<int> ck;

void dfs(int node) {
  if (root == node) {
    for (int x : v[node]) {
      dfs(x);
    }
    return;
  }
  if (C[node] == 0) {
    ck[P[node]] = 1;
  }
  for (int x : v[node]) {
    dfs(x);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> N;
  v = vector<vector<int>>(N + 5);
  C = vector<int>(N + 5);
  P = vector<int>(N + 5);
  ck = vector<int>(N + 5);
  for (int i = 0; i < N; i++) {
    cin >> P[i] >> C[i], P[i]--;
    if (P[i] == -2) {
      root = i;
      continue;
    }
    v[P[i]].emplace_back(i);
  }
  dfs(root);
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    if (ck[i] == 0 && C[i] == 1) ans.emplace_back(i);
  }
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  if (ans.size() == 0) cout << "-1";
  cout << '\n';
}
