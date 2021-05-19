#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d; cin >> n >> d;
  vector<int> a(n - 2); for (int &x : a) cin >> x;
  vector<pair<int, int>> cords(n);
  for (int i = 0; i < n; i++) {
    cin >> cords[i].first >> cords[i].second;
  }
}
