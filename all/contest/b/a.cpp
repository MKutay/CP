#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> a(N + 10);
	vector<vector<int>> dp(K + 10, vector<int>(N + 10, 1e18));
	for (int i = 0; i < N; i++) cin >> a[i];
	long long ans = 1e18;
	for (int i = 0; i < N; i++) {
		dp = vector<vector<int>>(K + 10, vector<int>(N + 10, 1e18));
		dp[0][N] = 0;
		for (int k = 1; k <= K; k++) {
			for (int j = 0; j < N; j++) {
				long long val = 0;
				for (int b = j + 1; b <= N; b++) {
					val += a[b - 1] * (b - j - 1);
					dp[k][j] = min(dp[k][j], val + dp[k - 1][b]);
				}
			}
		}
		ans = min(ans, dp[K][0]);
		rotate(a.begin(), a.begin() + 1, a.end());
	}
	cout << ans << '\n';
	return 0;
}

