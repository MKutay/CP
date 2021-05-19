#include<bits/stdc++.h>
using namespace std;

template<class T> T in() {T a; cin >> a; return a;}
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

int x = 1;

vector<int> power(int k) {
	vector<int> ans(5e5);
	ans[0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < x; j++) {
			ans[j] *= 2;
		}
		for (int j = 0; j < x; j++) {
			if (ans[j] >= 10) {
				ans[j] %= 10;
				ans[j + 1]++;
				if (j == x - 1) x++;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cerr.tie(0);
	vector<int> a = power(1000);
	long long ans = 0;
	for (int i = x - 1; i >= 0; i--) {
		ans += a[i];
	}
	cout << ans << '\n';
	return 0;
}
