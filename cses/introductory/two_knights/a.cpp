/**
 *  author: MKutayBozkurt
 *  created: 18.01.2021 18:08:11
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  for (int k = 1; k <= N; k++) {
    long long a1 = k * k, a2 = a1 * (a1 - 1) / 2;
    if (k > 2) {
      a2 -= 4 * (k - 1) * (k - 2);
    }
    cout << a2 << '\n';
  }
}
