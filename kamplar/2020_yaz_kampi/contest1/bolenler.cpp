#include<bits/stdc++.h>
using namespace std;

long long x, k, MAX = 100000;
map<long long, vector<long long>> divisors;
vector<long long> answer;

vector<long long> get_divisors(long long x) {

	vector<long long> divisors_L, divisors_R;
	for(long long i = 1; i * i <= x; i++) {
		if(x % i == 0) {
			divisors_L.push_back(i);
			if(x / i != i)
				divisors_R.push_back(x / i);
		}	
	}
	reverse(divisors_R.begin(), divisors_R.end());
	for(auto divisor: divisors_R)
		divisors_L.push_back(divisor);
	return divisors_L;

}

void construct_divisor_table() {

	vector<long long> divisors_v = get_divisors(x);
	for(int i = 0; i < (int) divisors_v.size(); i++) 
		for(int j = 0; j <= i; j++) 
			if(divisors_v[i] % divisors_v[j] == 0)
				divisors[divisors_v[i]].push_back(divisors_v[j]);

}
 
void construct(long long x, long long k) {

	if(x == 1 or k == 0) {
		if(MAX) {
			MAX--;
			answer.push_back(x);
		}
		return ;
	}
	for(auto d: divisors[x]) {
		construct(d, k - 1);
		if(!MAX)
			return ;
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> x >> k;
	construct_divisor_table();
	construct(x, k);
	for(auto value: answer)
		cout << value << ' ';

}
  			  			  				 	  								  	