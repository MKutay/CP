#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int n, q, o, arr[N];

struct segtree{
	
	int tree[4 * N];
	int ar[N];
	int nef = 1;

	void build(int node, int left, int right, function<int(int, int)> _do){
		if(left == right){
			tree[node] = ar[left];
			return;
		}
		build(node * 2, left, (left + right) / 2, _do);
		build(node * 2 + 1, (left + right) / 2 + 1, right, _do);
		tree[node] = _do(tree[node*2], tree[node*2+1]);
	}

	void update(int node, int left, int right, int in, int val, 
function<int(int, int)> _do){
		if(left > in || right < in)
			return;
		if(left == in && right == in){
			tree[node] = val;
			return;
		}

		update(node * 2, left, (left + right) / 2, in, val, _do);
		update(node * 2 + 1, (left + right) / 2 + 1, right, in, val, _do);
		tree[node] = _do(tree[node*2],tree[node*2+1]); 
	}

	int query(int node, int left, int right, int ltarget, int rtarget){
		if(left > rtarget || right < ltarget)
			return nef; 
		if(left >= ltarget && right <= rtarget)
			return tree[node];
		
		int a = query(node * 2, left, (left + right) / 2, ltarget, rtarget);
		int b = query(node * 2 + 1, (left + right) / 2 + 1, right , ltarget, rtarget);
		return a + b;
	}	

	void new_segtree(int a[], int size, function<int(int, int )> _do, int af){
		
		for(int i = 1;i <= size;i++)
			ar[i] = a[i];
		nef = af;
		build(1,1,size,_do);
	}	
};

int main(){
	cin >> n >> q;
	for(int i = 1;i <= n;i++)
		cin >> arr[i];

	auto op = [&](int a,int b) -> int{ return a + b; };
	segtree seg_sum;
	seg_sum.new_segtree(arr,n,op,0);
	
	while(q--){
		cin >> o >> a >> b;
		if(o == 1)
			seg_sum.update(1,1,n,a+1,b,op);
		else
			cout << seg_sum.query(1,1,n,a+1,b) << '\n';
	}
}
