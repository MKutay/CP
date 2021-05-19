#include<bits/stdc++.h>
#define LOG 10
using namespace std;
 
int n, x, y;
 
void send_answer(int pos_1, int pos_2) {
 
	if(pos_1 > pos_2)
		swap(pos_1, pos_2);
	cout << "! " << pos_1 << " " << pos_2 << "\n";
	fflush(stdout);
	exit(0);
 
}
 
int query(vector<int> query_set) {
 
	cout << "? " << (int) query_set.size() << " ";
	for(auto query: query_set)
		cout << query << " ";
	cout << "\n";
	fflush(stdout);
	int result_xor;
	cin >> result_xor;
	return result_xor;
 
}
 
int do_binary_search(vector<int> one_half) {
 
	int l = 0, r = (int) one_half.size();
	while(l + 1 < r) {
		int mid = ((l + r) >> 1);
		int exp_xor = ((mid - l) & 1) * x;
		vector<int> query_set(one_half.begin() + l, one_half.begin() + mid);
		if(query(query_set) != exp_xor) 
			r = mid;
		else 
			l = mid;
	}
	return one_half[l];
 
}
 
vector<int> get_one_half(int xor_of_p) {
 
	vector<int> one_half;
	vector<bool> covered(n + 1, 0);
	for(int i = 1; i <= n; i++) 
		if(not covered[i])
			if((i ^ xor_of_p) <= n) {
				covered[i] = 
				covered[i ^ xor_of_p] = true;
				one_half.push_back(i);
			}
	return one_half;
 
}
 
int divide_and_ask(int value) {
 
	vector<int> query_set;
	for(int i = 1; i <= n; i++) 
		if(!(i & value))
			query_set.push_back(i);
	int result_xor = query(query_set);
	if(result_xor != x * ((int) query_set.size() & 1))
		return value;
	return 0;
 
}
 
int find_xor_of_p() {
 
	int xor_of_p = 0;
	for(int i = 0; i < LOG; i++) 
		xor_of_p ^= divide_and_ask(1 << i);
	return xor_of_p;
 
}
 
int main() {
 
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
 
	cin >> n >> x >> y;
	int xor_of_p = find_xor_of_p();
	vector<int> one_half = get_one_half(xor_of_p);
	int pos_1 = do_binary_search(one_half);
	send_answer(pos_1, pos_1 ^ xor_of_p);
 
}
