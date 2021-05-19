#include <bits/stdc++.h>
using namespace std;

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	int size = 1;
	while(size < n)
		size <<= 1;
	
	vector<long long> tree((size << 2) + 5);
	
	[&]{//build
		for (int nd = size; nd < size + n; nd++) tree[nd] = v[nd - size]; 
		for (int nd = size << 1; nd >= 1; nd--) tree[nd] += tree[nd << 1] + tree[nd << 1 | 1];	
	}();

	auto modify = [&](int i, long long v) {
		tree[size + i] = v;
		for (int nd = (size + i) >> 1; nd >= 1; nd >>= 1) tree[nd] = tree[nd << 1] + tree[nd << 1 | 1];
	};
	
	auto query = [&](int l, int r) {
		long long ans = 0;           
		for(l += size, r += size; l <= r && l > 0 ; l >>= 1, r >>= 1) {
			if (l & 1) ans += tree[l++];
			if (r & 1 ^ 1) ans += tree[r--]; 
		}
		return ans; 
	};
}
