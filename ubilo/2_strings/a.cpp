#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("greedy1.gir", "r", stdin);
  freopen("greedy1.cik", "w", stdout);
  int N; cin >> N;
  string S, T; cin >> S >> T;
  S += "!";
  T += "!";

  int ans = 0;

  int flag = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] != T[i]) {
      flag = 1;
    } else if (flag) {
      ans++;
      flag = 0;
    }
  }

  if (S[N - 1] != T[N - 1]) ans++;
  cout << ans << '\n';
}
