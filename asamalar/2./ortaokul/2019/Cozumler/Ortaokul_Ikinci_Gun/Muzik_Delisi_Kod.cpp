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

using namespace std;

#define pb push_back
#define mp make_pair
#define nd second
#define st first

typedef long long ll;
typedef pair < int, int > pii;

const int inf = 1e9 + 9;
const int N = 2e5 + 9;
const int kokn = 350;
const int logN = 25;

int n, m, k;
int a[N];
map < int, int > cnt;
// int cnt[N];

int main() {

    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        if (i > m) {
            cnt[a[i - m]]--;
        }
        mx = max(mx, cnt[a[i]]);
    }

    cout << mx << endl;


    return 0;
}
