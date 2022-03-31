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
const int maxn = 5e5 + 7;
const int MOD = 1e9 + 7;

struct ds {
    int p[maxn];

    ds() {
        for (int i=0; i<maxn; i++)
            p[i] = i;
    }

    int clan(int x) {
        return x == p[x] ? x : (p[x] = clan(p[x]));
    }

    void join(int x, int y) {
        x = clan(x);
        y = clan(y);
        if(x == y)
            return;
        p[y] = x;
    }
}ds;

pii edge[maxn] = {};

int32_t main() {
    int i,j;
    int n,m;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            edge[i] = { x, m+1};
        } else {
            int x, y;
            cin >> x >> y;
            edge[i] = { x, y};
        }
    }
    int T = 1;
    vector<int> ans;
    for (int i=1; i<=n; i++) {
        if (ds.clan(edge[i].F) != ds.clan(edge[i].S)) {
            ds.join(edge[i].F, edge[i].S);
            ans.PB(i);
            T = T * 2 % MOD;
        }
    }
    printf("%lld %d\n", T, ans.size());
    for (auto it: ans)
        printf("%lld ", it);
    printf("\n");

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
