#include <bits/stdc++.h>
using namespace std;

int is_num(char c) {
  if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') 
    return 1;
  else 
    return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string S; cin >> S;
  int n = S.size();
  string temp = "";
  vector<string> nums;
  for (int i = 0; i < n; i++) {
    if (is_num(S[i])) {
      temp += S[i];
    } else {
      if (temp != "")
        nums.emplace_back(temp);
      temp = "";
    }
  }
  if (temp != "") {
    nums.emplace_back(temp);
  }
  map<string, int> m;
  for (auto &x : nums) {
    string new_x;
    bool flag = 0;
    for (int i = 0; i < x.size(); i++) {
      if (x[i] != '0') {
        flag = 1;
      }
      if (flag) {
        new_x += x[i];
      }
    }
    x = new_x;
    m[x]++;
  }
  cout << m.size() << '\n';
}
