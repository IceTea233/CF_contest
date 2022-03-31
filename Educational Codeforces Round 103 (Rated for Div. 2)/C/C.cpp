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
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int a[maxn];
int b[maxn];
int c[maxn];
int dp[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            scanf("%lld", &c[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld", &b[i]);

        // printf("OK\n");
        int ans = 0;
        dp[1] = abs(a[2] - b[2]) + 2;
        for (int i=2; i<=n; i++) {
            de(1) printf("i = %lld\n", i);
            int d = abs(a[i+1] - b[i+1]);
            ans = max(ans, dp[i-1] + (c[i]-1));

            if (i == n)
                break;
            if (a[i+1] == b[i+1])
                dp[i] = 2;
            else
                dp[i] = max(dp[i-1] + (c[i]-1 - d), d) + 2;
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
