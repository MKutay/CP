#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("typo.in", "r", stdin);
  freopen("typo.out", "w", stdout);
  string S; cin >> S;
  int n = S.size();
  int open = 0, close = 0;
  int d = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (S[i] == '(') {
      open++;
      d++;
    } else {
      close++;
      d--;
    }
    if (d <= 1) {
      open = 0;
    }
    if (d == -1) {
      ans = close;
      break;
    }
  }
  if (d > 0) {
    ans = open;
  }
  cout << ans << '\n';
}
