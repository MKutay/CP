#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include<bitset>

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

#define nd second
#define st first
#define mp make_pair
#define pb push_back
#define orta (((bas)+(son))/2)
#define sol (k+k)
#define sag (k+k+1)

const int N = 1e6 + 5;;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;
const int logN = 17;

int main() {
	
	int x, y;

	scanf("%d %d", &x, &y);

	if(x % 2 && y % 2) 
		printf("%d\n", x + y - 1);

	else printf("%d\n", x + y);	
	
	return 0;
}