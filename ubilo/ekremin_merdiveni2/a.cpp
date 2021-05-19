#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  freopen("ekreminmerdiveni.gir", "r", stdin);
  freopen("ekreminmerdiveni.cik", "w", stdout);
  int n; cin >> n;
  vector<int> a(n); for (int &x : a) cin >> x;
  sort(a.begin(), a.end());
  stack<int> s;
  queue<int> q;
  map<int, int> m;
  int l = 0;
  for (int i = 0; i < n; i++) {
    if (m[a[i]] == 1) s.push(a[i]);
    if (m[a[i]] == 0) {
      q.push(a[i]);
      l = a[i];
    }
    m[a[i]]++;
  }
  if (s.size())
    cout << q.size() + (s.top() == l ? s.size() - 1 : s.size()) << '\n';
  else 
    cout << q.size() << '\n';
  while (q.size()) {
    cout << q.front() << " ";
    q.pop();
  }
  while (s.size()) {
    if (s.top() != l) {
      cout << s.top() << " ";
    }
    s.pop();
  }
}
