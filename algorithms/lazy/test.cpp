#include <bits/stdc++.h>
using namespace std;

int main() {
  srand(time(0));
  ios::sync_with_stdio(0); cin.tie(0);
  vector<string> a = {"mehmet", "kutay", "bozkurt"};
  vector<string> rn;
  for (int i = 0; i < a[0].size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      for (int k = 0; k < a[1].size(); k++) {
        for (int l = 0; l < a[1].size(); l++) {
          for (int r = 0; r < a[2].size(); r++) {
            for (int f = 0; f < a[2].size(); f++) {
              rn.emplace_back(string() + a[0][i] + a[0][j] + a[1][k] + a[1][l] + a[2][r] + a[2][f]);
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << rn[rand() % 10000] << '\n';
  }
}
