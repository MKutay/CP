#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define MAXN 1000
#define INF 200000000
#define ll long long

using namespace std;

long long solve(string str)
{
    int n = str.length();

    map< pair<int, int>, ll > mp;

    mp[make_pair(0, 0)] = 1;
    ll zc = 0, oc = 0, tc = 0;

    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'F') zc++;
        else if (str[i] == 'R') oc++;
        else tc++;
        pair<int, int> tmp = make_pair(zc - oc,
                                       zc - tc);
        res = res + mp[tmp];

        mp[tmp]++;
    }

    return res;
}

int main()
{
    string str;
    int a;
    cin >> a;
    cin >> str;
    cout << solve(str) << endl;
    return 0;
}
