#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  map<string, int> m;
  for (int i = 0; i < n; i++) {
    string s; cin >> s;
    if (!m[s]) {
      cout << "OK\n";
    } else {
      cout << s << m[s] << '\n';
    }
    m[s]++;
  }
}
