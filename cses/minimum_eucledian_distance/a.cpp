/**
 *  video: https://www.twitch.tv/videos/884988969?filter=archives&sort=time
 *  author: MKutayBozkurt
 *  created: 23.01.2021 19:02:18
**/
#include <bits/stdc++.h>
using namespace std;

struct P {
	int x, y;
};

long long sq(long long a) {
	return a * a;
}

long long distance(const P &a, const P &b) {
	return sq(a.x - b.x) + sq(a.y - b.y);
}

long long smallest_distance(vector<P> points, vector<P> points_y) {
	int n = points.size();
	if (n <= 1) {
		return LLONG_MAX;
	}
	vector<P> left = vector<P>(points.begin(), points.begin() + n / 2);
	vector<P> right = vector<P>(points.begin() + n / 2, points.end());
	vector<P> left_y, right_y;
	for (P p : points_y) {
		if (make_pair(p.x, p.y) <= make_pair(left.back().x, left.back().y)) {
			left_y.emplace_back(p);
		} else {
			right_y.emplace_back(p);
		}
	}
	long long d1 = smallest_distance(left, left_y);
	long long d2 = smallest_distance(right, right_y);
	long long d = min(d1, d2);
	int middle_x = left.back().x;
	vector<P> stripe;
	for (P p : points_y) {
		if (sq(p.x - middle_x) < d) {
			stripe.emplace_back(p);
		}
	}
	for (int i = 0; i < (int) stripe.size(); i++) {
		for (int j = i + 1; j < (int) stripe.size() && sq(stripe[j].y - stripe[i].y) < d; j++) {
			d = min(d, distance(stripe[i], stripe[j]));
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	vector<P> points(N);
	for (P &p : points) {
		cin >> p.x >> p.y;
	}
	sort(points.begin(), points.end(), [&](const P &a, const P &b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	});
	vector<P> points_y = points;
	sort(points_y.begin(), points_y.end(), [&](const P &a, const P &b) {
		return a.y < b.y;
	});
	cout << smallest_distance(points, points_y) << '\n';
}
