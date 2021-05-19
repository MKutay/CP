#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long int lo;
#define pb push_back
#define st first
#define nd second
#define mp make_pair
lo MOD=1e9+7;
lo a,b,c,d,e,n,m,x,y,z,a1[500005],a2[100005],k,t;
char c1,c2,c3,c4;
string s1,s2,s3,s4;
bool av=0;
map <char,lo> mp1;

vector <lo> v1;
void f(){
    a1[0]=1;
    x=1;
    for(lo i=0;i<k;i++){
        for(lo j=0;j<x;j++){
            a1[j] = a1[j]*2;
        }
        for(lo j=0;j<x;j++){
            // if(j==x&&a1[j]>=10){
            //     x++;
            // }
            if(a1[j]>=10){
                a1[j] = a1[j]%10;
                a1[j+1]++;
                if(j==x-1)
                    x++;
            }
            
            // cout<<a1[j]<<endl;
        }
    }
}
int main() {
    freopen("2000k.gir","r",stdin);
	freopen("2000k.cik","w",stdout);
    cin>>k;
    f();
    // cout<<x<<endl;
    for(lo i=x-1;i>=0;i--){
        // if(a1[i]==0){
        //     continue;
        // }
        cout<<a1[i];
    }
    for(lo i=0;i<3*k;i++){
        cout<<0;
    }
    return 0;
}
