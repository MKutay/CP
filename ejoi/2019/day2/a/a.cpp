#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

const int inf = 1e9;
int n, m;
vector<vector<char>> a;
int sp() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	vector<vector<int>> ans(n, vector<int>(m, inf));
	pq.push({0, {0, 0}});
	while (pq.size()) {
		int z = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (x < 0 || y < 0 || x >= n || y >= m || ans[x][y] != inf) continue;
		ans[x][y] = z;
		if (a[x][y] == 'E') {
			if (ans[x][y + 1] == inf) pq.push({z, {x, y + 1}});
			if (ans[x + 1][y] == inf) pq.push({z + 1, {x + 1, y}});
			if (ans[x][y - 1] == inf) pq.push({z + 2, {x, y - 1}});
			if (ans[x - 1][y] == inf) pq.push({z + 3, {x - 1, y}});
		} else if (a[x][y] == 'S') {
			if (ans[x + 1][y] == inf) pq.push({z, {x + 1, y}});
			if (ans[x][y - 1] == inf) pq.push({z + 1, {x, y - 1}});
			if (ans[x - 1][y] == inf) pq.push({z + 2, {x - 1, y}});
			if (ans[x][y + 1] == inf) pq.push({z + 3, {x, y + 1}});
		} else if (a[x][y] == 'W') {
			if (ans[x][y - 1] == inf) pq.push({z, {x, y - 1}});
			if (ans[x - 1][y] == inf) pq.push({z + 1, {x - 1, y}});
			if (ans[x][y + 1] == inf) pq.push({z + 2, {x, y + 1}});
			if (ans[x + 1][y] == inf) pq.push({z + 3, {x + 1, y}});
		} else if (a[x][y] == 'N') {
			if (ans[x - 1][y] == inf) pq.push({z, {x - 1, y}});
			if (ans[x][y + 1] == inf) pq.push({z + 1, {x, y + 1}});
			if (ans[x + 1][y] == inf) pq.push({z + 2, {x + 1, y}});
			if (ans[x][y - 1] == inf) pq.push({z + 3, {x, y - 1}});
		}
	}
	return ans[n - 1][m - 1];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	/*
	her 4 yere bir cost ile gidiyon
	*/
	cin >> n >> m;
	a = vector<vector<char>>(n, vector<char>(m)); cin >> a;
	cout << sp() << '\n';
}
