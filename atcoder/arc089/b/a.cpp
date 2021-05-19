#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

const int N = 2007;
int cnt[3][N][N], pre[3][N][N], suf[3][N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<pair<int, pair<int, char>>> a(n);
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		char z; cin >> z;
		int dx = x / k;
		int dy = y / k;
		bool t = z == 'W';
		t ^= (dx & 1);
		t ^= (dy & 1);
		x %= k;
		y %= k;
		cnt[t][x][y]++;
	}
	for (int t = 0; t < 2; t++) {
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				pre[t][i + 1][j + 1] = pre[t][i + 1][j] + pre[t][i][j + 1] - pre[t][i][j] + cnt[t][i][j];
			}
		}
		for (int i = k - 1; i >= 0; i--) {
			for (int j = k - 1; j >= 0; j--) {
				suf[t][i][j] = suf[t][i + 1][j] + suf[t][i][j + 1] - suf[t][i + 1][j + 1] + cnt[t][i][j];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			for (int t = 0; t < 2; t++) {
				ans = max(ans, pre[t][i][j] + suf[t][i][j] + (pre[t ^ 1][k][k] - pre[t ^ 1][i][j] - suf[t ^ 1][i][j]));
			}
		}
	}
	cout << ans << '\n';
}
