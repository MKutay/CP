/**
 *  author: MKutayBozkurt
 *  created: 01.04.2021 17:35:54
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a; cin >> a;
  int b = sqrt(a);
  if (b * b == a) {
    cout << b << '\n';
  } else {
    cout << b + 1 << '\n';
  }
}
