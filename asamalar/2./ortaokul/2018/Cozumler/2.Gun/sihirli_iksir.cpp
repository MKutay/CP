#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>

using namespace std;

typedef pair < int, int > pii;

const int N = 1e5 + 5;;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const int logN = 17;

int n, m, x, y, z, a[N], k;

bool ctr(long long cur) {
	long long ret = k;
	for(int i = 1; i <= n; i++) {
		ret -= max(0LL, cur - a[i]);
		if(ret < 0) return 0;
	} return 1;
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	long long l = 0, r = 2000000000;
	while(l < r) {
		long long mid = (l + r + 1) / 2;
		if(ctr(mid)) l = mid;
		else r = mid - 1;
	} printf("%lld\n", l);
}