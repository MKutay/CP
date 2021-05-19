#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 100001;
int N;
int x[MAXN];
int LIS[MAXN];
int LDS[MAXN];
int lis[MAXN];
int lds[MAXN];
int tree[4 * MAXN];
int best;
int query(int node , int s , int e , int qs , int qe){
   if(s > qe || e < qs)
      return 0;
   if(s >= qs && e <= qe)
      return tree[node];
   return max(query(2 * node , s , (s+e)/2 , qs , qe) , query(2 * node + 1 , (s+e)/2+1, e , qs , qe));
}
void update(int node , int s , int e , int idx , int val){
   if(s == e && s == idx){
      tree[node] = val;
      return;
   }
   if(s > idx || e < idx)
      return;
   update(2 * node , s , (s+e)/2 , idx , val);
   update(2 * node + 1 , (s+e)/2 + 1 , e , idx , val);
   tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
   return;
}

int main(){
  cin >> N;
  for(int n = 1 ; n <= N ; n++)
    cin >> x[n];
  for(int n = 1 ; n <= N ; n++){
    LIS[n] = 1 + query(1 , 1 , N , 1 , x[n] - 1);
    //LIS[n] =+ 1 + query(1, x[n] - 1);
    update(1 , 1 , N , x[n] , LIS[n]);
    //update(x[n], LIS[n]);
    best = max(best , LIS[n]);
  }
  memset(tree , 0 , sizeof(tree));
  for(int n = N ; n >= 1 ; n--){
    LDS[n] = 1 + query(1 , 1 , N , x[n] + 1 , N);
    //LDS[n] = 1 + query(x[n] + 1, N);
    update(1 , 1 , N , x[n] , LDS[n]);
    //update(x[n], LDS[n]);
  }
  vector<int> res;
  for(int n = 1 ; n <= N ; n++){
    if(LIS[n] + LDS[n] - 1 == best)
    res.push_back(x[n]);
  }
  sort(res.begin() , res.end());
  cout << (int) res.size() << '\n';
  for (int pr : res) cout << pr << " ";
  cout << '\n';
  return 0;
}
