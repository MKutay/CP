#include<bits/stdc++.h>
using namespace std;

#define sz(x) ((int)x.size())

multiset < int > s;
int ans = 0 , last = 0 , Q;

int main() {

	scanf("%d",&Q);

	while ( Q-- ) {

		int t , a;
		scanf("%d %d",&t,&a);

		if( t == 1 ){
			if( a <= last ) 
				ans++;
			else
				s.insert(x);
		} 
		else {

			while ( sz(s) && *s.begin() <= x ) {
				s.erase ( s.begin() );
				ans++;
			}
			
			printf("%d\n",ans);
			last=x;
		}
	}

	return 0;
}