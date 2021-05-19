#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(string s1, string s2) {
	return s1 + s2 > s2 + s1;
}

int main() {
	int n;
	cin >> n;
	string s;
	vector< string > v;
	for(int i = 1; i <= n; i++) {
		cin >> s;
		v.push_back(s);	
	} 
	sort(v.begin(), v.end(), cmp);
	for(auto s: v)
		cout << s;
	cout << endl;
}
