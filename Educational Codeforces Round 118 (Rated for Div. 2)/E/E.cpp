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

vector<string> world;

int mask[4][2] = {
    { 1,  0},
    { 0,  1},
    {-1,  0},
    { 0, -1}
};

int n, m;
bool okay(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m && world[r][c] == '.';
}

void dfs(int cur_r, int cur_c) {
    vector<pii> keep;
    for (int i=0; i<4; i++) {
        int nxt_r = cur_r + mask[i][0];
        int nxt_c = cur_c + mask[i][1];
        if (okay(nxt_r, nxt_c))
            keep.PB({nxt_r, nxt_c});
    }

    if (keep.size() <= 1) {
        world[cur_r][cur_c] = '+';
    }
    if (keep.size() == 1) {
        dfs(keep[0].F, keep[0].S);
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        world.resize(n);
        int cur_r, cur_c;
        for (int i=0; i<n; i++) {
            cin >> world[i];
            for (int j=0; j<m; j++) {
                if (world[i][j] == 'L') {
                    cur_r = i;
                    cur_c = j;
                }
            }
        }

        // cout << "cur = " << cur_r << ", " << cur_c << "\n";

        for (int i=0; i<4; i++) {
            int nxt_r = cur_r + mask[i][0];
            int nxt_c = cur_c + mask[i][1];
            if (okay(nxt_r, nxt_c))
                dfs(nxt_r, nxt_c);
        }

        for (int i=0; i<n; i++) {
            cout << world[i] << "\n";
        }
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
