#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int main() {
  int t = 10;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    vector<int> d(n + 1, N), lis(n + 1), lds(n + 1);
    d[0] = -N;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int j = upper_bound(d.begin(), d.begin() + n, a[i]) - d.begin();
      j--;
      lis[i] = j + 1;
      if (d[j + 1] == N) {
        cnt++;
        d[j + 1] = a[i];
      
      } else {
        d[j + 1] = a[i];
      }
    }
    d = vector<int>(n + 1, N);
    d[0] = -N;
    reverse(a.begin(), a.end());
  }
}
