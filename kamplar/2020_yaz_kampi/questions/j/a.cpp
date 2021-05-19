#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    if ('A' <= s[i] && s[i] <= 'Z') a[i] = 1;
    else a[i] = 0;
  }
  for (int i = 0; i < n; i++) {

  }
}
