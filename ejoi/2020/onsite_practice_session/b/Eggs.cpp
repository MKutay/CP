#include <iostream>
#include "stub.h"

int solve(int n, int h) {
	int l = 1, r = h;
	while (l <= r) {
		if (n == 1) {
			for (int i = l; i <= r; i++) {
				int d = drop(i);
				if (d == 1) {
					return i;
				}
			}
		}
		int m = (l + r) / 2;
		int d = drop(m);
		if (d) {
			r = m - 1;
			n--;
		} else {
			l = m + 1;
		}
	}
	return r + 1;
}
