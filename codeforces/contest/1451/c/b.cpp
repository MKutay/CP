#include <bits/stdc++.h>
using namespace std;
int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    vector<int> ca(26), cb(26);
    for (auto c : a) ca[c - 'a']++;
    for (auto c : b) cb[c - 'a']++;
    bool f = 1;
    int sa = 0, sb = 0;
    for (int i = 0; i < 26; i++) {
      sa += ca[i];
      sb += cb[i];
      if (ca[i] % k != cb[i] % k || sa < sb) f = 0;
    }
    if (f) cout << "YES\n";
    else cout << "NO\n";
  }
}
