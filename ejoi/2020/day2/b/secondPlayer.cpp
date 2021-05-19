#include <bits/stdc++.h>
#include "stub.h"
using namespace std;
 
void guessCard(int s, int t, int tar) {
	int n = 52;
	if (tar < s) guess(tar);
	for (int i = s; i < s + t - 1; i++) {
		guess(i);
	}
}
