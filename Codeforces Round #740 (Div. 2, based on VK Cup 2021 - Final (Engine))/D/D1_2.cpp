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

struct bit {
    int arr[maxn] = {};
    void add(int x, int d) {
        while (x < maxn) {
            arr[x] = (arr[x] + d) % MOD;
            x += (x & -x);
        }
    }
    int query(int x) {
        int ret = 0;
        while (x) {
            ret = (ret + arr[x]) % MOD;
            x -= (x & -x);
        }
        return ret;
    }
    int sum(int l, int r) {
        return ((query(r) - query(l-1)) % MOD + MOD) % MOD;
    }
} dp;

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> MOD;
    // dp[n] = 1;
    dp.add(n, 1);
    for (int i=n-1; i>=1; i--) {
        int d1 = dp.sum(i+1, n);
        dp.add(i, d1);

        for (int j=2; i * j <= n; j++) {
            int d2 = dp.sum(i*j, min(n, i*j + j - 1));
            dp.add(i, d2);
        }
        // printf("dp[%lld] = %lld\n", i, dp.sum(i, i));
        // dp[i/2] = ( dp[i/2] + dp[i] ) % m;
    }

    int ans = dp.sum(1, 1);
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
