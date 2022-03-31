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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

struct stair {
    pii src;
    pii des;
    int heal;
};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> x(n+1);
        for (int i=1; i<=n; i++) {
            cin >> x[i];
        }

        vector<pii> src(k + 1);
        vector<pii> des(k + 1);
        vector<int> h(k + 1);
        vector<vector<stair>> up(n + 1);
        for (int i=1; i<=k; i++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d >> h[i];
            src[i] = {a, b};
            des[i] = {c, d};
            up[a].PB({src[i], des[i], h[i]});
        }

        vector< map<int,int> > dp(n + 1);
        dp[1][1] = 0;
        for (int i=1; i<=n; i++) {
            // cerr << ">>> i = " << i << "\n";
            if (dp[i].empty())
                continue;
            sort(begin(up[i]), end(up[i]), [](stair a, stair b) {
                return a.src.S < b.src.S;
            });


            // cerr << ">>> left to right \n";
            auto from = dp[i].begin();
            int cost = from->S;
            for (auto it : up[i]) {
                while (next(from) != dp[i].end() && next(from)->F <= it.src.S) {
                    cost = min(next(from)->S, cost + abs(next(from)->F - from->F) * x[i]);
                    from ++;
                }
                int dpVal = cost + abs(it.src.S - from->F) * x[i] - it.heal;
                auto udp = dp[it.des.F].find(it.des.S);
                if (udp == dp[it.des.F].end()) {
                    dp[it.des.F][it.des.S] = dpVal;
                } else {
                    dp[it.des.F][it.des.S] = min(dp[it.des.F][it.des.S], dpVal);
                }
            }

            // cerr << ">>> right to left \n";
            from = prev(dp[i].end());
            cost = from->S;
            for (auto it = up[i].rbegin(); it != up[i].rend(); it++) {
                while (from != dp[i].begin() && prev(from)->F >= it->src.S) {
                    cost = min(prev(from)->S, cost + abs(prev(from)->F - from->F) * x[i]);
                    from --;
                }
                int dpVal = cost + abs(it->src.S - from->F) * x[i] - it->heal;
                auto udp = dp[it->des.F].find(it->des.S);
                if (udp == dp[it->des.F].end()) {
                    dp[it->des.F][it->des.S] = dpVal;
                } else {
                    dp[it->des.F][it->des.S] = min(dp[it->des.F][it->des.S], dpVal);
                }
            }
            // cerr << "OK\n";
            de(1) {
                for (auto it : dp[i]) {
                    printf("dp[%lld][%lld] = %lld\n", i, it.F, it.S);
                }
            }
        }

        if (dp[n].empty()) {
            printf("NO ESCAPE\n");
        } else {
            int ans = INF;
            for (auto it : dp[n]) {
                ans = min(ans, it.S + x[n] * (m - it.F));
            }
            printf("%lld\n", ans);
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
