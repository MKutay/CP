#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(0));
  int n = (rand() % 10) + 1;
  cout << n << '\n';
  for (int i = 0; i < n; i++) {
    cout << (rand() % 100) + 1 << " ";
  }
  cout << '\n';
}
