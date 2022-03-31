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
const int maxn = 5e4 + 7;

int a[maxn] = {};
int dp[maxn][2][2] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        int x;
        cin >> x;
        for (int i=1; i<=n; i++) {
            a[i] -= x;
            dp[i][0][0] = -INF;
            dp[i][0][1] = -INF;
            dp[i][1][0] = -INF;
            dp[i][1][1] = -INF;
        }

        dp[1][0][0] = 0;
        dp[1][0][1] = 1;

        for (int i=2; i<=n; i++) {
            dp[i][0][0] = max(dp[i-1][0][0], dp[i-1][1][0]);
            dp[i][0][1] = max(dp[i-1][0][0], dp[i-1][1][0]) + 1;
            dp[i][1][0] = max(dp[i-1][0][1], dp[i-1][1][1]);
            if (a[i-1] + a[i] >= 0)
                dp[i][1][1] = max(dp[i][1][1], dp[i-1][0][1] + 1);
            if (a[i-1] + a[i] >= 0 && a[i-2] + a[i-1] + a[i] >= 0)
                dp[i][1][1] = max(dp[i][1][1], dp[i-1][1][1] + 1);
        }

        // for (int i=1; i<=n; i++) {
        //     printf(">> %lld %lld %lld %lld\n", dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
        // }

        int ans = 0;
        ans = max({dp[n][0][0], dp[n][0][1], dp[n][1][0], dp[n][1][1]});
        // cerr << "ans = ";
        cout << ans << "\n";
    }

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
