#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, x; cin >> n >> x;
  string s; cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') {
      if (x != 0) x--;
    } else {
      x++;
    }
  }
  cout << x << '\n';
}
