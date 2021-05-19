/**
 *  author: MKutayBozkurt
 *  created: 21.02.2021 21:17:48
**/
#include <bits/stdc++.h>
using namespace std;

struct item {
  int x, y, z;
};

struct segtree {
	int n;
	vector<item> tree;

  item sum(item a, item b) {
    return item{a.x + b.x, a.y + b.y, a.z + b.z};
  }

	void init(int N) {
		n = 1;
		while (n < N) n *= 2;
		tree.assign(2 * n, item{0, 0, 0});
	}

	void build(string &A, int x, int lx, int rx) {
		if (rx - lx == 1) {
      if (lx < (int) A.size()) {
        item tmp;
        tmp.x = (A[lx] == 'x');
        tmp.y = (A[lx] == 'y');
        tmp.z = (A[lx] == 'z');
				tree[x] = tmp;
      }
			return;
		}
		int m = (lx + rx) / 2;
		build(A, 2 * x + 1, lx, m);
		build(A, 2 * x + 2, m, rx);
		tree[x] = sum(tree[2 * x + 1], tree[2 * x + 2]);
	}
	void build(string &A) {
		build(A, 0, 0, n);
	}

	item query(int l, int r, int x, int lx, int rx) {
		if (lx >= r || l >= rx) return item{0, 0, 0};
		if (lx >= l && rx <= r) return tree[x];
		int m = (lx + rx) / 2;
		item L = query(l, r, 2 * x + 1, lx, m);
		item R = query(l, r, 2 * x + 2, m, rx);
		return sum(L, R);
	}
	item query(int l, int r) {
		return query(l, r, 0, 0, n);
	}
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string S; cin >> S;
  int N = S.size();
  segtree st;
  st.init(N);
  st.build(S);
  int M; cin >> M;
  while (M--) {
    int L, R; cin >> L >> R, L--, R--;
		if (R - L + 1 < 3) {
			cout << "YES\n";
			continue;
		}
    item a = st.query(L, R);
		a.x += (S[R] == 'x');
		a.y += (S[R] == 'y');
		a.z += (S[R] == 'z');
    //cout << a.x << " " << a.y << " " << a.z << '\n';
		cout << (max({a.x, a.y, a.z}) - min({a.x, a.y, a.z}) <= 1 ? "YES" : "NO") << '\n';
  }
}
