#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> a;

int check(int m) {
  int w = 0, res = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > m) return 0;
  }
  for (int i = 0; i <= n; i++) {
    res += a[i];
    if (res + a[i + 1] > m) {
      w++;
      res = 0;
    }
  }
  if (w + 1 > c) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("adilahmet.gir", "r", stdin);
  freopen("adilahmet.cik", "w", stdout);
  cin >> n;
  a = vector<int>(n + 5);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  cin >> c;
  int l = 0, r = s;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << (l + r) / 2 << '\n';
}
