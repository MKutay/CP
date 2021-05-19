#include <bits/stdc++.h>
#include "stub.h"
using namespace std;
 
void swapCards(int cards[], int s, int t) {
	int n = 52;
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = cards[i];
	for (int i = 0; i < s; i++) {
		if (a[i] != i) {
			for (int j = 0; j < n; j++) {
				if (a[j] == i) {
					swap(a[j], a[i]);
					doSwap(i, j);
				}
			}
		}
	}                   
}