#include "xylophone.h"

vector<int> a

void solve(int n) {
	a = vector<int>(n);
	// 1 3 2 5 4
	//  2 1 3 1
	//   2 3 3
	//    4 3
	//     4
}

/*  vector<int> f(n);
  f[1] = query(1, 2);
  for (int i = 2; i < n; ++i) {
    int th = query(i - 1, i + 1), tw = query(i, i + 1);
    if (th == abs(f[i - 1])) {
      f[i] = f[i - 1] + (f[i - 1] > 0 ? -1 : 1) * tw;
    } else if (th > abs(f[i - 1])) {
      if (tw > th) {
        f[i] = f[i - 1] + (f[i - 1] > 0 ? -1 : 1) * tw;          
      } else {
        f[i] = f[i - 1] + (f[i - 1] > 0 ? 1 : -1) * tw;          
      }       
    }      
  } */
