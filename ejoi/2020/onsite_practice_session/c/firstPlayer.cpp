#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

int createNew(int n, int a, int b) {
	a++;
	b++;
	if (a == 1 && b == 2) {
		a = 3;
		b = 4;
	} else if (a == 1 && b == 3) {
		a = 2;
		b = 4;
	} else if (a == 1 && b == 4) {
		a = 2;
		b = 3;
	} else if (a == 2 && b == 3) {
		a = 1;
		b = 4;
	} else if (a == 2 && b == 4) {
		a = 1;
		b = 3;
	} else if (a == 3 && b == 4) {
		a = 1;
		b = 2;
	} else {
		assert(false);
	}
	a--;
	b--;
	return n * a + b;
}

