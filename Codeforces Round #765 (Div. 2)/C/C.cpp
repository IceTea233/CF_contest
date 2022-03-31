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
const int maxn = 5e2 + 7;

int d[maxn] = {};
int a[maxn] = {};
int dp[2][maxn][maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n, l, k;
    cin >> n >> l >> k;

    for (int i=0; i<n; i++) {
        cin >> d[i];
    }
    d[n] = l;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            dp[0][i][j] = INF;
        }
    }
    dp[0][0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int h=0; h<=k; h++) {
                dp[(i+1)&1][j][h] = INF;
            }
        }

        for (int j=0; j<=i; j++) {
            for (int h=0; h<=k; h++) {
                dp[(i+1)&1][i][h] = min(dp[i&1][j][h] + (d[i+1] - d[i]) * a[i],
                                    dp[(i+1)&1][i][h]);
                dp[(i+1)&1][j][h+1] = min( dp[i&1][j][h] + (d[i+1] - d[i]) * a[j],
                                        dp[(i+1)&1][j][h+1]);
            }
        }

        for (int j=0; j<=i+1; j++) {
            for (int h=0; h<=k; h++) {
                printf("dp[%lld][%lld][%lld] = %lld\n", i + 1, j, h, dp[(i+1)&1][j][k]);
            }
        }
        printf("\n");
    }

    int ans = INF;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=k; j++) {
            ans = min(ans, dp[n&1][i][j]);
        }
    }
    // cerr << "ans = ";
    printf("%lld\n", ans);

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
