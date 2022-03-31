#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int n,a,b,da,db;
vector<int> G[maxn];
int dep[maxn] = {};

int lf;
void dfs(int x, int p, bool chk) {
    if (x == b)
        chk = 1;
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dep[y] = dep[x] + 1;
        dfs(y, x, chk);
    }
    if (chk && G[x].size() == 1) {
        lf = x;
    }
}

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> da >> db;
        for (i=1; i<=n; i++)
            G[i].clear();
        for (i=1; i<=n-1; i++) {
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        if (da*2 >= db) {
            printf("Alice\n");
            continue;
        }

        dep[a] = 0;
        dfs(a, 0, 0);
        de(1) printf(">>> %lld\n", dep[b]);
        if (dep[b] > da)
            printf("Bob\n");
        else
            printf("Alice\n");
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
