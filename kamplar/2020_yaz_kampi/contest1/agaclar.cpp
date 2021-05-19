#include<bits/stdc++.h>
using namespace std;
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 
	int n;
	cin >> n;
	vector<int> f(100000 + 5, 0);
	int mx = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x -= min(i, n - i - 1);
		if(x > 0)
			mx = max(mx, ++f[x]);
	}
	cout << n - mx;
 
}