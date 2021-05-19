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

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> ans;
	int l = 0, r = n - 1;
	bool p = 1;
	for (int i = 0; i < n; i++) {
		if (!p)
			ans.emplace_back(a[l++]);
		else 
			ans.emplace_back(a[r--]);
		p ^= 1;
	}
	int res = 0;
	for (int i = 1; i < n - 1; i++) {
		if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) res++;
	}
	cout << res << '\n';
	for (int x : ans) {
		cout << x << " ";
	}
	cout << '\n';
}
