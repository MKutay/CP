/**
 *  author: MKutayBozkurt
 *  created: 31.01.2021 15:58:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 0; i < n; i++) {
    int d = a[i].first + a[i].second;
    for (int j = 0; j < n; j++) {
      int e = a[j].first + a[j].second;
      if (d == a[j].first && e == a[i].first) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
