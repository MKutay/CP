// https://www.youtube.com/watch?v=kPaJfAUwViY

#include <bits/stdc++.h>
using namespace std;

vector<int> table, a;
int n;

void update(int i, int delta) {
  while (i < n + 1) {
  	table[i] += delta;
  	i += i & -i;
  }
}

int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += table[i];
		i -= i & -i;
	}
	return s;
}

int rangeSum(int i, int j) {
	return sum(j) - sum(i);		
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	return 0;
}




