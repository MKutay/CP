/**
 *  author: MKutayBozkurt
 *  created: 19.12.2020 12:35:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    string R, B; cin >> R >> B;
    int s = 0;
    for (int i = 0; i < N; i++) {
      if (R[i] > B[i]) s++;
      else if (B[i] > R[i]) s--;
    }
    if (s > 0) cout << "RED\n";
    else if (s < 0) cout << "BLUE\n";
    else cout << "EQUAL\n";
  }
}
