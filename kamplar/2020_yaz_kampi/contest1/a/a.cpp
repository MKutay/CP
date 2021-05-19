#include <bits/stdc++.h>
using namespace std;

void check(vector<int> ans) {
  if ((int) ans.size() >= 100000) {
    for (int i = 0; i < 100000; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  long long w, k; cin >> w >> k;
  int sq = sqrt(w) + 1;
  set<int> dd;
  for (int i = 1; i <= sq; i++) {
    if (w % i == 0) {
      dd.insert(i);
      dd.insert(w / i);
    }
  }
  vector<int> d;
  for (int x : dd) {
    d.push_back(x);
  }

  int n = d.size();

  if (k == 0) {
    cout << w << '\n';
    return 0;
  }

  if (k == 1) {
    for (int i = 0; i < n; i++) {
      cout << d[i] << " ";
    }
    cout << '\n';
    return 0;
  }
}
