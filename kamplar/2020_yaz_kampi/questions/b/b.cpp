#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("dizi4.gir", "r", stdin);
  freopen("dizi4.cik", "w", stdout);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  map<int, int> m;
  for (int x : a) m[x]++;
  sort(a.begin(), a.end());
  int mx = -1;
  for (int x : a) {
    mx = max(mx, m[x]);
  }
  for (int x : a) {
    if (m[x] == mx) {
      cout << x << '\n';
      return 0;
    }
  }
}
