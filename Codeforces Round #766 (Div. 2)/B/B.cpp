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
const int maxn = 1e5 + 7;

int mask[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > table(n);
        for (int i=0; i < n; i++) {
            table[i].resize(m);
        }
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                table[i][j] = 0;
            }
        }

        table[0][0] = n + m - 2;
        table[n - 1][0] = n + m - 2;
        table[0][m - 1] = n + m - 2;
        table[n - 1][m - 1] = n + m - 2;

        queue<pii> que;
        que.push({0, 0});
        que.push({0, m - 1});
        que.push({n - 1, 0});
        que.push({n - 1, m - 1});
        while (que.size()) {
            pii cur = que.front();
            // printf("cur = %lld, %lld\n", cur.first, cur.second);
            que.pop();
            for (int i=0; i < 4; i++) {
                int nxt_x = cur.first + mask[i][0];
                int nxt_y = cur.second + mask[i][1];
                if (0 <= nxt_x && nxt_x < n && 0 <= nxt_y && nxt_y < m && !table[nxt_x][nxt_y]) {
                    table[nxt_x][nxt_y] = table[cur.first][cur.second] - 1;
                    que.push({nxt_x, nxt_y});
                }
            }
        }

        vector<int> ans;
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                ans.PB(table[i][j]);
            }
        }
        sort(all(ans));
        for (auto it : ans)
            printf("%lld ", it);
        printf("\n");
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
