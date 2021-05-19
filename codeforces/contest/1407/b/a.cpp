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

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int cur = 0;
	while (a.size()) {
		int mx = 0, ind = 0;
		for (int i = 0; i < (int) a.size(); i++) {
			int g = gcd(a[i], cur);
			if (g > mx) {
				mx = g;
				ind = i;
			}
		}
		cur = mx;
		cout << a[ind] << " ";
		a.erase(a.begin() + ind);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while (t--) solve();
}
