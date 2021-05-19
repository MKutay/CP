#include <bits/stdc++.h>
using namespace std;
struct P {
	int x, y;
};
 
long long sq(long long a) {
	return a * a;
}
long long distance(const P& a, const P& b) {
	return sq(a.x-b.x)+sq(a.y-b.y);
}
 
// returns square of smallest distance
long long smallest_distance(vector<P> points, vector<P> points_by_y) { // O(N*log(N)) just like merge sort
	int n = points.size();
	if(n <= 1) {
		return LLONG_MAX;
	}
	vector<P> left = vector<P>(points.begin(), points.begin() + n / 2);
	vector<P> right = vector<P>(points.begin() + n / 2, points.end());
	vector<P> left_by_y, right_by_y;
	for(P p : points_by_y) {
		if(make_pair(p.x, p.y) <= make_pair(left.back().x, left.back().y)) {
			left_by_y.push_back(p);
		}
		else {
			right_by_y.push_back(p);
		}
	}
	long long d1 = smallest_distance(left, left_by_y);
	long long d2 = smallest_distance(right, right_by_y);
	long long d = min(d1, d2);
	int middle_x = left.back().x; // can be right[0].x or anything in between
	vector<P> stripe;
	for(P p : points_by_y) {
		if(sq(p.x-middle_x) < d) {
			stripe.push_back(p);
		}
	}
	for(int i = 0; i < (int) stripe.size(); ++i) {
		// every stripe[i], pair up with points above it by at most d
		// lemma says that the following for-loop is O(1)
		for(int j = i + 1; j < (int) stripe.size() && sq(stripe[j].y-stripe[i].y) < d; ++j) {
			d = min(d, distance(stripe[i], stripe[j]));
		}
	}
	return d;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<P> points(n);
	for(P& p : points) {
		scanf("%d%d", &p.x, &p.y);
	}
	sort(points.begin(), points.end(), [&](const P& a, const P& b) {
		return make_pair(a.x, a.y) < make_pair(b.x, b.y);
	});
	vector<P> points_by_y = points;
	sort(points_by_y.begin(), points_by_y.end(), [&](const P& a, const P& b) {
		return a.y < b.y;
	});
	cout << smallest_distance(points, points_by_y) << endl;
}
