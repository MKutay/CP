#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  vector<int> m(5);
  vector<int> a(n); for (int &x : a) {
    cin >> x;
    m[x]++;
  }
  int mx = 0;
  for (int i = 1; i <= 3; i++) {
    mx = max(m[i], mx);
  }
  cout << n - mx << '\n';
}
