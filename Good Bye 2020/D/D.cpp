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

set<int> G[maxn] = {};
int cnt[maxn] = {};
int w[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cnt[i] = 0;
            G[i].clear();
            cin >> w[i];
        }

        for (int i=1; i<=n-1; i++) {
            int u,v;
            cin >> u >> v;
            G[u].insert(v);
            cnt[u]++;
            G[v].insert(u);
            cnt[v]++;
        }
        priority_queue<pii, vector<pii>, less<pii>> pq;
        vector<int> ans;
        int tt = 0;
        for (int i=1; i<=n; i++) {
            tt += w[i];
            if (cnt[i] > 1) {
                pq.push({w[i], i});
            }
        }
        ans.PB(tt);
        for (int i=1; i<=n-2; i++) {
            if (!pq.empty()) {
                auto x = pq.top();
                pq.pop();
                tt += x.F;
                cnt[x.S]--;
                if (cnt[x.S] > 1) {
                    pq.push(x);
                }
            }
            ans.PB(tt);
        }

        for (auto it: ans)
            printf("%lld ", it);
        printf("\n");
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
