#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define pb push_back
#define int long long int

int t, n, a, elimde;
float W;
bool yazdim;
vector<pair<int, int> > v;
vector<int> k;

int32_t main(){
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> n >> W;
		v.clear();
		k.clear();
		elimde = 0;
		yazdim = false;
		for (int j = 0; j < n; ++j)
		{
			cin >> a;
			v.pb({-a, j+1});
		}
		sort(v.begin(), v.end());
		for (int j = 0; j < v.size(); ++j)
		{
			if((-1*v[j].st) <= W){
				elimde -= v[j].st;
				k.pb(v[j].nd);
			}
			if(elimde >= ceil(W/2) && elimde <= W){
				cout << k.size() << endl;
				sort(k.begin(), k.end());
				for (int u = 0; u < k.size(); ++u)
				{
					cout << k[u] << " ";
				}
				yazdim = true;
				cout << endl;
				break;
			}	
		}
		if(yazdim == false){
			cout << -1 << endl;
		}
	}
}
