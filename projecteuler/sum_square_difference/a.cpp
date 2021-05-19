#include <bits/stdc++.h>

using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

typedef long long int lo;
#define pb push_back
#define st first
#define nd second
#define inf (int)1e9
#define N (int)1e5 * 5
#define mod (int)1e9 + 7
#define all(x) (x).begin(), (x).end()
int in(){ int a; cin >> a; return a; }

void solve(){
	int n = 100;
	lo ans1 = 0;
	lo ans2 = 0;
	for(int i = 1 ; i <= n ; i++){
		ans1 += i * i;
		ans2 += i;
	}
	cout << abs(ans1 - (ans2 * ans2)) << endl;
}

int main(){
  	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0); cerr.tie(0);
	// freopen("gir.gir", "r", stdin);
	// freopen("cik.cik", "w", stdout);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}