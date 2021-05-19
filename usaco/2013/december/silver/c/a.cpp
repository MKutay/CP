#include <bits/stdc++.h>
using namespace std;

template<typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &x : v) is >> x;
  return is;
}

const int mxN = 100010;

int X[mxN];
int Y[mxN];
int PI[mxN];

void compose(int* R, int* A, int* B, int N) {
	for (int i = 0; i < N; i++) {
		R[i] = A[B[i]];
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
	int N, M, Q; cin >> N >> M >> Q;
	int T = N - M + 1;
	for (int i = 0; i < N; i++) {
		X[i] = i;
		if (i < M) {
			int x; cin >> x, x--;
			PI[x] = i;
		} else {
			PI[i] = i;
		}
	}
	rotate(PI, PI + 1, PI + N);

	for (int i = 31 - __builtin_clz(T); i >= 0; i--) {
		compose(Y, X, X, N);
		memcpy(X, Y, sizeof(X));
		if (T & 1 << i) {
			compose(Y, X, PI, N);
			memcpy(X, Y, sizeof(X));
		}
	}
	while (Q--) {
		int x; cin >> x;
		cout << X[(N + M - 1 - x) % N] + 1 << '\n';
	}
}
