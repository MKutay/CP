#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  for (char &c : s) {
    for (int i = 0; i < n; i++) {
      if (c == 'Z') c = 'A';
      else c++;
    }
  }
  cout << s << '\n';
}
