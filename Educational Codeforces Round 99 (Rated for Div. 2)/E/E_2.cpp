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
#define x F
#define y S
#define de(x) if(x && x == MODE)
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 10;

pii P[maxn] = {};
pii Q[maxn] = {};
bool v[maxn] = {};

int ans;
void dfs(int idx, int sum) {
    // printf(">>> (%lld, %lld)\n", idx, sum);
    if (idx == 4) {
        ans = min(ans, sum);
        return;
    }
    for (int i=0; i<4; i++) {
        if (!v[i]) {
            v[i] = 1;
            int d = abs(P[idx].x - Q[i].x) + abs(P[idx].y - Q[i].y);
            dfs(idx+1, sum+d);
            v[i] = 0;
        }
    }
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        for (int i=0; i<4; i++) {
            cin >> P[i].x >> P[i].y;
        }
        vector<int> X, Y;
        for (int i=0; i<4; i++) {
            X.PB(P[i].x);
            Y.PB(P[i].y);
        }
        sort(all(X));
        sort(all(Y));
        int l = X[1];
        int r = X[2];
        int d = Y[1];
        int u = Y[2];
        if (r-l < u-d) {
            if (r-l < u-d && l > X[0]) {
                l -= min(l-X[0], (u-d) - (r-l));
            }
            while (r-l < u-d)
                r += (u-d) - (r-l);
        } else if (r-l > u-d){
            while (r-l > u-d && d > Y[0])
                d -= min(d-Y[0], (r-l) - (u-d));
            while (r-l > u-d)
                u += (r-l) - (u-d);
        }
        Q[0] = {l, d};
        Q[1] = {l, u};
        Q[2] = {r, d};
        Q[3] = {r, u};
        // for (int i=0; i<4; i++) {
        //     printf("(%lld ,%lld)\n", Q[i].x, Q[i].y);
        // }
        ans = INF;
        dfs(0, 0);
        printf("%lld\n", ans);
    }

    return 0;
}

//
//          ___ ___  __________  __________
//         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
//        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
//       ////   \ \  \ \  \      \ \\\\\\\\\\\
//      ////__   \ \  \ \  \      \ \\\\_____/
//     ///////\   \ \  \ \  \______\ \\\\_______   ________
//    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
//   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
//                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
// ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
//   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
//                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
//                               \/__/    \/________/\/__/   \/__/
//
