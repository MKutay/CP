#include <bits/stdc++.h>
using namespace std;

int g2(string s) {
  char c = s[0];
  if (c == '1') {
    if (s == "10") return 3;
    if (s == "11") return 6;
    if (s == "12") return 6;
    if (s == "13") return 8; //thirteen
    if (s == "14") return 8; // fourteen
    if (s == "15") return 7; // fifteen
    if (s == "16") return 7;
    if (s == "17") return 9;
    if (s == "18") return 8; // eighteen
    if (s == "19") return 8;
  }
  if (c == '2') return 6; // twenty
  if (c == '3') return 6; // thirty
  if (c == '4') return 5; // forty
  if (c == '5') return 5; // fifty
  if (c == '6') return 5; // sixty
  if (c == '7') return 7; // seventy
  if (c == '8') return 6; // eighty
  if (c == '9') return 6; // ninety
}

int g(char c) {
  if (c == '0') return 4;
  if (c == '1') return 3;
  if (c == '2') return 3;
  if (c == '3') return 5;
  if (c == '4') return 4;
  if (c == '5') return 5;
  if (c == '6') return 3;
  if (c == '7') return 5;
  if (c == '8') return 5;
  if (c == '9') return 4;
}

int f(string s) {
  if (s.size() == 1) {
    return g(s[0]);
  } else if (s.size() == 2) {
    if (s[0] == '1') {
      return g2(s);
    } else {
      if (s[1] == '0') {
        return g2(s);
      } else {
        return g2(s) + g(s[1]);
      }
    }
  } else if (s.size() == 3) {
    int ans = 0;
    if (s[0] == '1') {
      ans = g2(s);
    } else {
      if (s[1] == '0') {
        ans = g2(s);
      } else {
        ans = g2(s) + g(s[1]);
      }
    }
    return g(s[0]) + 7 + 3 + ans;
  } else if (s.size() == 4) {
    return 3 + 7;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n = 1000;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    string s; to_string(i);
    ans += f(s);
  }
}
