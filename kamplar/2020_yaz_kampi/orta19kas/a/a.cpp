#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  map<char, int> m;
  for (char c : s) {
    m[c]++;
  }
  int mn = 1e9, mx = 0;
  for (auto c : s) {
    mn = min(m[c], mn);
    mx = max(m[c], mx);
  }
  if (mn == mx && mn == 2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
