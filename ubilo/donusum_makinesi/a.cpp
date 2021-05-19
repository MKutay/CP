#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("donusum.gir", "r", stdin);
  freopen("donusum.cik", "w", stdout);
  string A, B; cin >> A >> B;
  int n = A.size(), m = B.size();
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    a[i] = (A[i] == 'A' ? 1 : 2);
  }
  for (int i = 0; i < m; i++) {
    b[i] = (B[i] == 'A' ? 1 : 2);
  }
  
  vector<int> pa(n), pb(m);
  for (int i = 0; i < n; i++) {
    pa[i] = (i == 0 ? a[i] : pa[i - 1] + a[i]);
  }

  for (int i = 0; i < m; i++) {
    pb[i] = (i == 0 ? b[i] : pb[i - 1] + b[i]);
  }

  int Q; cin >> Q;
  while (Q--) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    l1--, r1--, l2--, r2--;

    int aa = pa[r1] - (l1 == 0 ? 0 : pa[l1 - 1]);
    int bb = pb[r2] - (l2 == 0 ? 0 : pb[l2 - 1]);
    
    //cerr << aa << " " << bb << '\n';

    cout << (aa % 3 == bb % 3 ? "YES" : "NO") << '\n';
  }
}
