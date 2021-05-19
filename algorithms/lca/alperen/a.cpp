#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;

long long n, q, ans[N], cnt, a, b, parent[N], setsizes[N], ancestor[N];

bool visited[N];

vector<long long> graph[N];

vector<pair<long long, long long>> queries[N];

long long setfind(long long a){
	if(a == parent[a]) return parent[a];
	else return parent[a] = setfind(parent[a]);
}

void setunion(long long a, long long b){
	a = setfind(a);
	b = setfind(b);

	if(a != b){
		if(setsizes[b] > setsizes[a]) swap(a, b);
		setsizes[a] += setsizes[b];
		parent[b] = parent[a];
	}
}

void lca(long long v){
	visited[v] = true;

	ancestor[v] = v;

	for(auto i : graph[v]){
		if(!visited[i]){
			lca(i);
			setunion(v, i);
			ancestor[setfind(v)] = v;
		}
	}

	for(auto i : queries[v]){
		if(visited[i.first]){
			ans[i.second] = ancestor[setfind(i.first)];
		}
	}
}

int main(){    
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	freopen("lca.gir", "r", stdin);freopen("lca.cik", "w", stdout);
	
	cin >> n >> q;

	for(int i = 1; i <= n; i++){
		cin >> cnt;

		while(cnt--){
			cin >> a;
			graph[i].push_back(a);
			graph[a].push_back(i);
		}
	}

	for(int i = 0; i < q; i++){
		cin >> a >> b;

		queries[a].push_back({b, i});
		queries[b].push_back({a, i});
	}

	iota(parent + 1, parent + n + 1, 1);
	fill(setsizes + 1, setsizes + n + 1, 0);

	lca(1);

	for(int i = 0; i < q; i++) cout << ans[i] << "\n";
}
