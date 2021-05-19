#include <bits/stdc++.h>
using namespace std;

// Range Minimum Query RMQ

vector<int> lo, hi, mn, delta;

void init(int m);
void build(int i, int a, int b);
void inc(int a, int b, int val);
int minim(int a, int b);
void prop(int i);
void update(int i);
void increment(int i, int a, int b, int val);
int minimum(int i, int a, int b);

int func(int a, int b) {
	return a + b;
}

void init(int m) {
	lo = vector<int>(4 * m + 1);
	hi = vector<int>(4 * m + 1);
	mn = vector<int>(4 * m + 1);
	delta = vector<int>(4 * m + 1);
	build(1, 0, m - 1);
}

void build(int i, int a, int b) {
	lo[i] = a;
	hi[i] = b;
	if (a == b) {
		return;
	}
	int m = (a + b) / 2;
	build(2 * i, a, m);
	build(2 * i + 1, m + 1, b);
}

void inc(int a, int b, int val) {
	increment(1, a, b, val); 
}

int minim(int a, int b) {
	return minimum(1, a, b);
}

void prop(int i) {
	delta[2 * i]  += delta[i];
	delta[2 * i + 1] += delta[i];
	delta[i] = 0;
}

void update(int i) {
	mn[i] = min(mn[2 * i] + delta[2 * i], mn[2 * i + 1] + delta[2 * i + 1]);
}

void increment(int i, int a, int b, int val) {
	if (b < lo[i] || hi[i] < a) {
		return;
	}
	if (a <= lo[i] && hi[i] <= b) {
		delta[i] += val;
		return;
	}
	prop(i);
	increment(2 * i, a, b, val);
	increment(2 * i + 1, a, b, val);
	update(i);
}

int minimum(int i, int a, int b) {
	if (b < lo[i] || hi[i] < a) {
		return INT_MAX;
	}
	if (a <= lo[i] && hi[i] <= b) {
		return mn[i] + delta[i];
	}
	prop(i);
	
	int mnLeft = minimum(2 * i, a, b);
	int mnRight = minimum(2 * i + 1, a, b);
	
	update(i);
	return min(mnLeft, mnRight);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	init(n);
	int q;
	cin >> q;
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int a,  b;
			cin >> a >> b;
			cout << minim(a, b) << '\n';
		} else if (c == 2) {
			int a, b, val;
			cin >> a >> b >> val;
			inc(a, b, val);
		}
	}
	return 0;
}
