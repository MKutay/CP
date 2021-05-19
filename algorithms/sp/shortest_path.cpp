#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int sp1(vector<vector<pair<int, int>>> v, int n, int m) {
  vector<int> ans(n + 1, inf);
  priority_queue<pair<int, int>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    int x = pq.top().first;
    int y = pq.top().second;
    pq.pop();
    if (ans[y] != inf) continue;
    ans[y] = -x;
    for (auto node : v[y]) {
      if (ans[node.first] == inf) {
        pq.push({x - node.second, node.first});
      }
    }
  }
  return ans[n];
}

int sp2(vector<vector<pair<int, int>>> v, int n, int m) {
  vector<int> ans(n + 1, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    int x = pq.top().first;
    int y = pq.top().second;
    pq.pop();
    if (ans[y] != inf) continue;
    ans[y] = x;
    for (auto node : v[y]) {
      if (ans[node.first] == inf) {
        pq.push({x + node.second, node.first});
      }
    }
  }
  return ans[n];
}

int sp3(vector<vector<pair<int, int>>> v, int n, int m) {
  vector<int> ans(n + 1, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 1});
  while (pq.size()) {
    int x = pq.top().first;
    int y = pq.top().second;
    pq.pop();
    for (auto node : v[y]) {
      if (x + node.second < ans[node.first]) {
        pq.push({x + node.second, node.first});
        ans[node.first] = x + node.second;
      }
    }
  }
  return ans[n];
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0); cerr.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> v(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }
  cout << sp1(v, n, m) << endl;
  cout << sp2(v, n, m) << endl;
  cout << sp3(v, n, m) << endl;
  return 0;
}

