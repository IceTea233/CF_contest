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

int n, m;
int a[maxn] = {};
int bit[maxn] = {};

void add(int x, int d) {
    while (x <= n*m) {
        bit[x] += d;
        x += x & (-x);
    }
}

int query(int x) {
    int ret = 0;
    while (x) {
        ret += bit[x];
        x -= x & (-x);
    }
    return ret;
}

int sum(int l, int r) {
    return query(r) - query(l-1);
}

bool cmp(pii a, pii b) {
    if (a.F == b.F)
        return a.S > b.S;
    return a.F < b.F;
}

int pos[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {

        cin >> n >> m;

        memset(bit, 0, sizeof(int) * (n*m+1));
        for (int i=1; i<=n*m; i++) {
            scanf("%lld", &a[i]);
        }

        vector<pii> keep;
        for (int i=1; i<=n*m; i++) {
            keep.PB({a[i], i});
        }
        sort(all(keep), cmp);
        for (int i=1; i<=n*m; i++) {
            pos[keep[i-1].S] = i;
        }

        // for (int i=1; i<=n*m; i++) {
        //     printf("%lld ", pos[i]);
        // }
        // printf("\n");

        int ans = 0;
        for (int i=1; i<=n*m; i++) {
            ans += query(pos[i]);
            // printf("add %lld\n", query(pos[i]));
            add(pos[i], 1);
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
