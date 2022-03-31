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

int m;
int bit[2][maxn] = {};
int a[2][maxn] = {};

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
    int t;

    cin >> t;
    while (t--) {
        cin >> m;

        reset();
        for (int i=1; i<=m; i++) {
            scanf("%lld", &a[0][i]);
            add(0, i, a[0][i]);
        }
        for (int i=1; i<=m; i++) {
            scanf("%lld", &a[1][i]);
            add(1, i, a[1][i]);
        }

        int ans = INF;
        for (int i=1; i<=m; i++) {
            ans = min(ans, max(sum(0, i+1, m), sum(1, 1, i-1)));
        }
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
