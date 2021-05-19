#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0); cerr.tie(0);
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		//if (s[i] < 'a') s[i] += 'a' - 'A';
		if (s[i] == '1') cout << 'q';
		if (s[i] == '2') cout << 'w';
		if (s[i] == '3') cout << 'e';
		if (s[i] == '4') cout << 'r';
		if (s[i] == '5') cout << 't';
		if (s[i] == '6') cout << 'y';
		if (s[i] == '7') cout << 'u';
		if (s[i] == '8') cout << 'i';
		if (s[i] == '9') cout << 'o';
		if (s[i] == '0') cout << 'p';
		if (s[i] == 'q') cout << 'a';
		if (s[i] == 'w') cout << 's';
		if (s[i] == 'e') cout << 'd';
		if (s[i] == 'r') cout << 'f';
		if (s[i] == 't') cout << 'g';
		if (s[i] == 'y') cout << 'h';
		if (s[i] == 'u') cout << 'j';
		if (s[i] == 'i') cout << 'k';
		if (s[i] == 'o') cout << 'l';
		if (s[i] == 'a') cout << 'z';
		if (s[i] == 's') cout << 'x';
		if (s[i] == 'd') cout << 'c';
		if (s[i] == 'f') cout << 'v';
		if (s[i] == 'g') cout << 'b';
		if (s[i] == 'h') cout << 'n';
		if (s[i] == 'j') cout << 'm';
		if (s[i] == ' ') cout << " ";
	}
  return 0;
}

