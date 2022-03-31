#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define PP pop_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 2e5 + 7;


#define x F
#define y S

const int mask[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

pii P[maxn] = {};
bool vis[maxn] = {};
pair<int, pii> dp[maxn];

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    map<pii, int> table;
    for (int i=1; i<=n; i++) {
        table[P[i]] = i;
    }

    queue<int> que;
    for (int i=1; i<=n; i++) {
        bool flag = false;
        for (int j=0; j<4; j++) {
            int nx = P[i].x + mask[j][0];
            int ny = P[i].y + mask[j][1];
            if (!table[{nx,ny}]) {
                flag = true;
                dp[i] = {1, {nx, ny}};
                vis[i] = true;
            }
        }
        if (flag)
            que.push(i);
    }

    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        // printf("NOW: %lld\n", cur);
        for (int i=0; i<4; i++) {
            int nx = P[cur].x + mask[i][0];
            int ny = P[cur].y + mask[i][1];

            if (table[{nx, ny}]) {
                int nxt = table[{nx, ny}];
                // printf("nxt = %lld\n", nxt);
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    que.push(nxt);
                    dp[nxt] = {dp[cur].F + 1, dp[cur].S};
                } else {
                    if (dp[cur].F + 1 < dp[nxt].F) {
                        dp[nxt] = {dp[cur].F + 1, dp[cur].S};
                    }
                }
            }
        }
    }

    // printf("ans = \n");
    for (int i=1; i<=n; i++) {
        printf("%lld %lld\n", dp[i].S.x, dp[i].S.y);
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
