/**
 *  author: MKutayBozkurt
 *  created: 23.01.2021 13:28:53
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int A, B; cin >> A >> B;
  if (A < B) swap(A, B);
  if (B + 3 > A) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
