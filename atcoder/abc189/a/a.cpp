/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 15:00:12
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  char a, b, c; cin >> a >> b >> c;
  if (a == b && b == c) {
    cout << "Won\n";
  } else {
    cout << "Lost\n";
  }
}
