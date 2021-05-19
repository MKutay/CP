/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:43:29
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int A, B; cin >> A >> B;
    if ((A + B) % 3 == 0 && 2 * A >= B && 2 * B >= A) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
