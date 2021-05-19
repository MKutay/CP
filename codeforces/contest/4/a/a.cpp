#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int N; cin >> N;
  cout << (N == 2 || N & 1 ? "NO" : "YES") << '\n';
}
