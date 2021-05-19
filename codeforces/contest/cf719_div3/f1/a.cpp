/**
 *  author: MKutayBozkurt
 *  created: 05.05.2021 17:37:08
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N, T; cin >> N >> T;
  int K; cin >> K;
  auto ask = [&](int l, int r) {
    cout << "? " << l << " " << r << '\n';
    int ret; cin >> ret;
    return (ret == -1 ? exit(0) : ret);
  };
  auto answer = [&](int ans) {
    cout << "! " << ans << '\n';
    exit(0);
  };
}
