/**
 *  author: MKutayBozkurt
 *  created: 25.03.2021 21:40:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    vector<int> A(N); for (int &x : A) cin >> x;
    set<int> s;
    map<int, int> m;
    for (int i = 0; i < N; i++) s.insert(A[i]), m[A[i]]++;
    for (int x : s) cout << x << " ";
    for (auto p : m) {
      if (p.second > 1) {
        for (int i = 0; i < p.second - 1; i++) 
          cout << p.first << " ";
      }
    }
    cout << '\n';
  }
}
