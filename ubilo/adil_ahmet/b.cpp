#include <bits/stdc++.h>

using namespace std;

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta ((bas + son)/2)
#define right (k + k + 1)
#define left (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define mod 1000000007
#define inf mod

#define endl '\n'
#define endll puts("")

#define N 25

typedef pair < int ,int > pii;

typedef long long ll;

int n, a[N], c, bas = 0, son;

int dene(int cozum){
    int calisan = 0, top = 0;
    FOR(i, 1, n)
    if(a[i] > cozum)
        return 0;
    FOR(i, 0, n){
        top += a[i];
        if(top + a[i + 1]> cozum){
            calisan++;
            top = 0;
        }
    }
    if(calisan + 1 > c)
        return 0;
    return 1;
}

int main () {
    //freopen("adilahmet.gir", "r", stdin); freopen("adilahmet.cik", "w", stdout);
    scanf("%d",&n);
    FOR(i, 1, n){
        scanf("%d", &a[i]);
        son += a[i];
    }
    //a[n + 1] = inf;
    scanf("%d",&c);
    while(bas < son){
        if(dene(orta))
            son = orta;
        else
            bas = orta + 1;
    }
    cout << orta;
    return 0;
}
