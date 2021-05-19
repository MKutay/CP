#include <bits/stdc++.h>
#define N 200005
#define M 20000005
using namespace std;
using ll = long long;

struct SegState {
	ll ans, pre, sz;

	SegState operator+(SegState rhs) const {
		SegState res;
		res.ans = ans + rhs.ans + sz*rhs.pre - rhs.sz*pre;
		res.pre = pre + rhs.pre;
		res.sz = sz + rhs.sz;
		return res;
	}
};

const SegState ID = {0, 0, 0}; // identity

struct SegNode {
	SegNode *lft, *rgt;
	SegState val;

	SegNode();
	~SegNode();
	SegState query(int l, int r, int lq, int rq);
	void update(int l, int r, int x, bool add);
};

int nd_cnt = 0;
SegNode nds[M];

inline ll mid(ll l, ll r) {
	ll sum = l+r;
	if (sum >= 0) return sum / 2;
	else return (sum-1) / 2;
}

SegNode::SegNode() : lft(nullptr), rgt(nullptr), val(ID) {}

SegNode::~SegNode() {
	if (lft) delete lft;
	if (rgt) delete rgt;
}

SegState SegNode::query(int l, int r, int lq, int rq) {
	if (r < lq || rq < l) return ID;
	if (lq <= l && r <= rq) return val;

	if (!lft) lft = new SegNode();
	if (!rgt) rgt = new SegNode();

	int m = mid(l, r);
	return lft->query(l, m, lq, rq) + rgt->query(m+1, r, lq, rq);
}

void SegNode::update(int l, int r, int x, bool add) {
	if (l == r) {
		if (add) val.sz++, val.pre += x;
		else val.sz--, val.pre -= x;
		return;
	}
	
	if (!lft) lft = new SegNode();
	if (!rgt) rgt = new SegNode();

	int m = mid(l, r);
	if (x <= m) {
		if (!lft) lft = new SegNode();
		lft->update(l, m, x, add);
	} else {
		if (!rgt) rgt = new SegNode();
		rgt->update(m+1, r, x, add);
	}
	val = (lft ? lft->val : ID) + (rgt ? rgt->val : ID);
}

int n, pos[N], q;
SegNode seg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("sorgulamaca.1.gir", "r", stdin);
	//freopen("sorgulamaca.cik", "w", stdout);

	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>pos[i];
		seg.update(INT_MIN, INT_MAX, pos[i], true);
	}

	cin>>q;
	while (q--) {
		int t, x, y; cin>>t>>x>>y;

		if (t == 1) {
			seg.update(INT_MIN, INT_MAX, pos[x], false);
			pos[x] += y;
			seg.update(INT_MIN, INT_MAX, pos[x], true);
		}

		if (t == 2) {
			cout<<seg.query(INT_MIN, INT_MAX, x, y).ans<<endl;
		}
	}
}
