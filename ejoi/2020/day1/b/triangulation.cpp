#include <bits/stdc++.h>
#include "stub.h"
using namespace std;
 
int solve(int n) {
	vector<vector<int>> m(n, vector<int>(n));
	int l = 0, r = n / 2;
	if (n & 1) {
		for (int i = 0; i < n / 2; i++) {
			if (m[l][r] || m[r][l]) continue;
			int q1 = query(l, r);
			if (q1) {
				return n * l + r;
			}
			int q2 = query(l, r + 1);
			if (q2) {
				return n * l + r + 1;
			}
			m[l][r] = 1;
			m[r][l] = 1;
			m[l][r + 1] = 1;
			m[r + 1][l] = 1;
			l++; r++;
		}
		int q1 = query(n / 2, n - 1);
		if (q1) {
			return n * (n / 2) + (n - 1);
		}
	} else {
		for (int i = 0; i < n / 2; i++) {
			if (m[l][r] || m[r][l]) continue;
			int q = query(l, r);
			m[l][r] = 1;
			m[r][l] = 1;
			if (q) {
				return n * l + r;
			}
			l++; r++;
		}
	} 
	return n / 2;
}