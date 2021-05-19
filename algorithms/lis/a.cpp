#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;

long long n, arr[N];

vector<long long> lists;

long long lis(){
	lists.push_back(arr[0]);

	for(int i = 1; i < n; i++){
		if(arr[i] < lists[0]) lists[0] = arr[i];
		else if(arr[i] > lists.back()) lists.push_back(arr[i]);
		else{
			auto it = lower_bound(lists.begin(), lists.end(), arr[i]);
			if(it != lists.end()){
				*it = arr[i];
			}
		}
	}

	return lists.size();
}

int main(){    
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	cin >> n;

	for(int i = 0; i < n; i++) cin >> arr[i];

	cout << lis();
}
