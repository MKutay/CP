#include <bits/stdc++.h>

using namespace std;

int in(){ int a; cin >> a; return a; }
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
long long tau(long long num){
  long long n = num;
  long long i = 2;
  long long p = 1;

  if(num == 1) return 1;

  while(i * i <= n){
    long long c = 1;
    while(n % i == 0){
        n /= i;
        c++;
    }
    i++;
    p *= c;
  }

  if(n == num || n > 1)
    p *= 1 + 1;

  return p;
}
int main(){
  ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(0); cerr.tie(0);
	long long x = 500;
	long long n = 1;
  long long d = 1;

  while(tau(d) <= x){
    n++;
    d += n;
  }
  cout << d << endl;
}
