#include<bits/stdc++.h>
using namespace std;

#define sim template<class c
#define ris return *this
#define dor > debug& operator<<
#define eni(x) sim > typename \
	enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e;};
sim > rge<c> range(c i, c j) {return rge<c>{i, j};}
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() {cerr << '\n';}
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair<b, c> d) {
	ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
	*this << "[";
	for (auto it = d.b; it != d.e; it++) 
		*this << (it == d.b ? "" : ", ") << *it;
	ris << "]";
}
#else
sim dor(const c&) {ris;}
#endif
};
#define imie(...) " [" << #__VA_ARGS__": " << (__VA_ARGS__) << "] "

int in(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int a; cin >> a;
	if (a == -1) exit(0);
	return a;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), vis(n);
	int j = 0;
	for (int i = 0; i < n; i++) {
		int x = in(i + 1, j + 1);
		int y = in(j + 1, i + 1);
		if (x < y) {
			a[j] = y;
			vis[y - 1] = 1;
			j = i;
		} else {
			a[i] = x;
			vis[x - 1] = 1;
		}
	}
	cout << "! ";
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}
