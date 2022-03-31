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

int n, m;
char s[maxn] = {};
int bit[6][maxn] = {};

void add(int id, int x, int d) {
    while (x <= m) {
        bit[id][x] += d;
        x += (x & -x);
    }
}

int query(int id, int x) {
    int ret = 0;
    while (x) {
        ret += bit[id][x];
        x -= (x & -x);
    }
    return ret;
}

int sum(int id, int l, int r) {
    if (l > r)
        return 0;
    return query(id, r) - query(id, l-1);
}

void reset() {
    for (int i=1; i<=m; i++) {
        bit[0][i] = 0;
        bit[1][i] = 0;
    }
}

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> m;
    scanf("%s", s+1);
    for (int i=1; i<=n; i++) {
        if (s[i] != ('a' + (i - 1) % 3))
            add(0, i, 1);
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != ('a' + (i) % 3))
            add(1, i, 1);
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != ('a' + (i + 1) % 3))
            add(2, i, 1);
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != ('c' - (i - 1) % 3))
            add(3, i, 1);
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != ('c' - (i) % 3))
            add(4, i, 1);
    }
    for (int i=1; i<=n; i++) {
        if (s[i] != ('c' - (i + 1) % 3))
            add(5, i, 1);
    }

    while (m--) {
        int l, r;
        scanf("%lld %lld", &l, &r);
        int ans = INF;
        for (int i=0; i<6; i++)
            ans = min(ans, sum(i, l, r));
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
