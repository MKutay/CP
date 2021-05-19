#include <algorithm>
#include <iostream>

using namespace std;

int n;
int f(int n){
	if(n == 1)
		return 1;

	if(n%2 == 0)
		return f(n/2)*2;
	else{
		int t = f(n/2) + 1;
		if(t > n/2)
			t -= n/2;
		return t*2;
	}
}

int main(){
	cin >> n;

	cout << f(n) << endl;
}