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

int n, MOD;

struct SGT {
    int tree[maxn*4] = {};
    int tag[maxn*4] = {};

    int LC(int i) {return i*2;}
    int RC(int i) {return i*2+1;}
    void pull(int i) {
        tree[i] = (tree[LC(i)] + tree[RC(i)]) % MOD;
    }
    void push(int l, int r, int i) {
        int m = (l + r) / 2;
        tree[LC(i)] = (tree[LC(i)] + tag[i] * (m - l + 1)) % MOD;
        tree[RC(i)] = (tree[RC(i)] + tag[i] * (r - m)) % MOD;
        tag[LC(i)] = (tag[LC(i)] + tag[i]) % MOD;
        tag[RC(i)] = (tag[RC(i)] + tag[i]) % MOD;
        tag[i] = 0;
    }
    void upd(int x1, int x2, int d, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            tree[i] = (tree[i] + (r - l + 1) * d) % MOD;
            tag[i] = (tag[i] + d) % MOD;
            return;
        }
        int m = (l + r) / 2;
        push(l, r, i);
        if (x1 <= m)
            upd(x1, x2, d, l, m, LC(i));
        if (m+1 <= x2)
            upd(x1, x2, d, m+1, r, RC(i));
    }
    int query(int x1, int x2, int l, int r, int i=1) {
        if (x1 <= l && r <= x2) {
            return tree[i];
        }
        int m = (l + r) / 2;
        int ret = 0;
        if (x1 <= m)
            ret = (ret + query(x1, x2, l, m, LC(i))) % MOD;
        if (m+1 <= x2)
            ret = (ret + query(x1, x2, m+1, r, RC(i))) % MOD;
        return ret;
    }
} dp;

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> MOD;
    // dp[n] = 1;
    dp.upd(n, n, 1, 1, n);
    for (int i=n-1; i>=1; i--) {
        int d1 = dp.query(i+1, n, 1, n);
        dp.upd(i, i, d1, 1, n);

        for (int j=2; i * j <= n; j++) {
            int d2 = dp.query(i*j, min(n, i * (j + 1) - 1), 1, n);
            dp.upd(i, i, d2, 1, n);
        }
        // dp[i/2] = ( dp[i/2] + dp[i] ) % m;
    }

    int ans = dp.query(1, 1, 1, n);
    printf("%lld\n", ans);

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
