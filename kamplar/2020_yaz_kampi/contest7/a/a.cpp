#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int k, b; cin >> k >> b;
    if (k * x + b >= 0) a[i] = k * x + b;
    else a[i] = 0;
  }
}
