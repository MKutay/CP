#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int n) {
	if(n > 1)
    return n * f(n - 1);
  else
    return 1;
}
int32_t main() {
	freopen("perm.gir","r",stdin);
	freopen("perm.cik","w",stdout);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) s++;
    }
    int x = f(n - i - 1);
    ans = ans + (x * (a[i] - 1 - s));
  }
  cout << ans + 1 << '\n';
}

