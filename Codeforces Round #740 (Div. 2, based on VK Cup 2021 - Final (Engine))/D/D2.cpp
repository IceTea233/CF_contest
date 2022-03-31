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
const int maxn = 4e6 + 7;

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
        return (query(r) - query(l-1)) % MOD;
    }
} dp;

int32_t main() {
    cin.tie(0);
    int i,j;

    cin >> n >> MOD;
    dp.add(n, 1);
    for (int i=n-1; i>=1; i--) {
        int d1 = dp.sum(i+1, n);
        dp.add(i, d1);

        for (int j=2; i * j <= n; j++) {
            int l = i*j;
            int r= min(n, (i + 1) * j - 1);
            int d2 = dp.sum(l, r);
            printf("add(dp[%lld, %lld] for %lld)\n", l, r, i);
            dp.add(i, d2);
        }
        // int d2 = dp.sum(i*2, n);
        // dp.add(i, d2);
        // printf("dp[%lld] = %lld\n", i, dp.sum(i, i));
    }

    int ans = dp.sum(1, 1);
    printf("%lld\n", (ans + MOD) % MOD);

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
