#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 4 * n; i > 2 * n; i -= 2) {
      cout << i << " ";
    }
    cout << '\n';
  }
}
