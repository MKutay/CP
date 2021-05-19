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

#define int long long

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, x; cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			b[i] = x - a[i];
		}
		int s = 0;
		for (int c : b) {
			s += c;
		}
		if (*max_element(a.begin(), a.end()) == *min_element(a.begin(), a.end()) && *max_element(a.begin(), a.end()) == x) {
			cout << "0\n";
		} else if (s == 0) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}
}
