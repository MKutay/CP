#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int d, t; cin >> d >> t;
  int s1 = 0, s2 = 0;
  vector<pair<int, int>> a(d);
  for (int i = 0; i < d; i++) {
    cin >> a[i].first >> a[i].second;
    s1 += a[i].first;
    s2 += a[i].second;
  }
  if (t < s1 || t > s2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> ans(d);
  for (int i = 0; i < d; i++) {
    ans[i] = a[i].first;
  }
  t -= s1;
  int k = 0;
  while (t > 0) {
    int b = min(a[k].second, ans[k] + t);
    t -= b - ans[k];
    ans[k] = b;
    k++;
  }
  for (int x : ans) cout << x << " ";
  cout << '\n';
}
