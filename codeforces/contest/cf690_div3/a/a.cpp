/**
 *  author: MKutayBozkurt
 *  created: 16.12.2020 11:08:12
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    if (n & 1) {
      for (int i = 0; i <= n / 2; i++) {
        if (i == n / 2) {
          cout << a[i] << " ";
        } else {
          cout << a[i] << " " << a[n - i - 1] << " ";
        }
      }
    } else {
      for (int i = 0; i < n / 2; i++) {
        cout << a[i] << " " << a[n - i - 1] << " ";
      }
    }
    cout << '\n';
  }
}
