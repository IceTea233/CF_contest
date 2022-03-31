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
const int maxn = 3e5 + 7;

int dp_l[2][maxn] = {};
int dp_r[2][maxn] = {};
int ans[maxn] = {};
char s[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        scanf("%s", s+1);
        dp_l[0][0] = 0;
        dp_l[1][0] = 0;
        for (int i=2; i<=n+1; i++) {
            if (s[i-1] == 'L') {
                dp_l[0][i] = dp_l[1][i-1] + 1;
                dp_l[1][i] = 0;
            } else {
                dp_l[0][i] = 0;
                dp_l[1][i] = dp_l[0][i-1] + 1;
            }
        }
        dp_r[0][n+1] = 0;
        dp_r[1][n+1] = 0;
        for (int i=n; i>=1; i--) {
            if (s[i] == 'L') {
                dp_r[0][i] = dp_r[1][i+1] + 1;
                dp_r[1][i] = 0;
            } else {
                dp_r[0][i] = 0;
                dp_r[1][i] = dp_r[0][i+1] + 1;
            }
        }

        de(1) {
            for (int i=0; i<=n+1; i++) {
                printf("%lld ", dp_r[0][i]);
            }
            printf("\n");
            for (int i=0; i<=n+1; i++) {
                printf("%lld ", dp_r[1][i]);
            }
            printf("\n");
        }

        for (int i=1; i<=n+1; i++)
            ans[i] = dp_l[0][i] + dp_r[1][i] + 1;
        for (int i=1; i<=n+1; i++)
            printf("%lld ", ans[i]);
        printf("\n");
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
