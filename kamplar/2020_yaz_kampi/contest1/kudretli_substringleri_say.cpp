#include<bits/stdc++.h>
using namespace std;
 
const int MAX = 100005;
int cnt[2][2][MAX];
 
int main() {
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
 
	string s;
	cin >> s;
	int n = s.size();
	long long ans[2] = {0};
	for(int i = 0; i < n; i++) {
		++cnt[s[i] == 'b'][i & 1][i];
		if(i)
			for(int i0 = 0; i0 < 2; i0++)
				for(int i1 = 0; i1 < 2; i1++)
					cnt[i0][i1 & 1][i] += cnt[i0][i1 & 1][i - 1];
		ans[0] += cnt[s[i] == 'b'][!(i & 1)][i];
		ans[1] += cnt[s[i] == 'b'][i & 1][i];
	}
	cout << ans[0] << " " << ans[1];
 
}
