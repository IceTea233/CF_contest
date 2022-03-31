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
const int maxn = 5e3 + 7;
const int MOD = 1e9 + 7;

int a[maxn] = {};

int dp[maxn][maxn] = {};
int cnt[maxn] = {};

int32_t main() {
    int i,j;
    int n,k,q;

    cin >> n >> k >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];

    for (i=1; i<=n; i++) {
        dp[0][i] = 1;
        cnt[i] = 1;
    }

    for (int i=1; i<=k; i++) {
        for  (int j=1; j<=n; j++) {
            dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) % MOD;
            cnt[j] = ( cnt[j] + dp[i][j] ) % MOD;
        }
    }

    for (int i=1; i<=n; i++)
        printf("%lld ", cnt[i]);
    printf("\n");

    int ans = 0;
    for (int i=1; i<=n; i++)
        ans = ( ans + cnt[i] * a[i] % MOD ) % MOD;
    while(q--) {
        int idx, x;
        scanf("%lld %lld", &idx, &x);
        ans = ( (ans + cnt[idx] * (x-a[idx]) ) % MOD + MOD ) % MOD;
        a[idx] = x;
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
