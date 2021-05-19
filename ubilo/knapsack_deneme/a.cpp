#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("knapsack3.gir", "r", stdin);
  freopen("knapsack3.cik", "w", stdout);
  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N, K; cin >> N >> K;
    vector<int> banknotes = {1, 5, 10, 20, 100};
    int k = 4;
    int ans = 0;
    while (N > 0) {
      if (banknotes[k] > N) {
        k--;
        continue;
      }
      int a = N % banknotes[k];
      int b = N / banknotes[k];
      ans += b;
      N = a;
    }
    if (K >= ans) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    if (i != T - 1) cout << "--\n";
  }
}
