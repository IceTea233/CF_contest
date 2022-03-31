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

set<int> G[maxn];
int F[maxn] = {};
int sz[maxn] = {};

void prepare(int n) {
    F[0] = 1;
    F[1] = 1;
    for (int i=2; F[i-1] < n; i++) {
        F[i] = F[i-1] + F[i-2];
    }
}

bool ans = 1;
pii cut = {};
void dfs(int x, int p, int f) {
    sz[x] = 1;
    for (auto y : G[x]) {
        if (y == p)
            continue;
        dfs(y, x, f);
        sz[x] += sz[y];
    }
    if (sz[x] == F[f-1])
        cut = {x, p};
    if (sz[x] == F[f-2])
        cut = {p, x};
}

void guess(int x, int f) {
    // printf("guess(%lld, %lld)\n", x, F[f]);
    if (f <= 1)
        return;
    cut = {0, 0};
    dfs(x, 0, f);
    pii keep = cut;
    // printf("cut = (%lld, %lld)\n", keep.F, keep.S);
    if (cut.F == 0) {
        ans = 0;
        return;
    }


    G[keep.F].erase(keep.S);
    G[keep.S].erase(keep.F);

    guess(keep.F, f-1);
    guess(keep.S, f-2);
}

int32_t main() {
    int i,j;
    int n;

    cin >> n;
    prepare(n);
    for (int i=1; i<=n-1; i++) {
        int u,v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    int f = 0;
    for (int i=0; ; i++) {
        // printf("F[%lld] = %lld\n", i, F[i]);
        if (F[i] == n) {
            f = i;
            break;
        } else if (F[i] > n) {
            printf("NO\n");
            return 0;
        }
    }
    // printf("f = %lld\n", F[f]);
    guess(1, f);
    if (ans)
        printf("YES\n");
    else
        printf("NO\n");

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
