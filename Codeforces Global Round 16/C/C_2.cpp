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

char M[3][maxn] = {};
int dp[maxn][4] = {};

int mask[4] = {0, 1, 0, 2};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        scanf("%s", M[1] + 1);
        scanf("%s", M[2] + 1);
        for (int i=0; i<=n; i++) {
            dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = -INF;
        }
        dp[0][0] = 0;

        for (int i=1; i<=n; i++) {
            int k = 0;
            if (M[1][i] == '0' || M[2][i] == '0')
                k |= 1;
            if (M[1][i] == '1' || M[2][i] == '1')
                k |= 2;

            // printf("k = %lld\n", k);

            for (int j=0; j<4; j++) {
                dp[i][j | k] = max( dp[i-1][j], dp[i][j | k]);
            }

            dp[i][0] = max({dp[i][1] + mask[1], dp[i][2] + mask[2], dp[i][3] + mask[3]});
        }

        // for (int i=1; i<=n; i++) {
        //     for (int j=0; j<4; j++) {
        //         printf("%lld ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        int ans = max(0LL, dp[n][0]);
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
