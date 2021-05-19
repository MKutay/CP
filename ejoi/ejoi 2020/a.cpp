#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int dp[100005][20];
int water[100005][20];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, diam, a, b;
    cin >> n >> q;
    priority_queue<pair<int, int>> pq; // diameter, id
 
    for (int i = 1; i <= n; i++) {
        cin >> diam >> water[i][0];
        while(!pq.empty() && -pq.top().first < diam) {
            dp[pq.top().second][0] = i;
            pq.pop();
        }
        pq.push({-diam, i});
    }
 
    while(!pq.empty()) {
        dp[pq.top().second][0] = 0;
        pq.pop();
    }
 
    dp[0][0] = 0;
    water[0][0] = 0;
 
    for (int j = 1; j <= 19; j++) {
        for (int i = 0; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
            water[i][j] = water[i][j - 1] + water[dp[i][j - 1]][j - 1];
        }
    }
 
    while(q--) {
        cin >> a >> b;
        for (int j = 19; j >= 0; j--) {
            if (water[a][j] >= b) {continue;}
            b -= water[a][j];
            a = dp[a][j];
        }
 
        cout << a << "\n";
    }
}
