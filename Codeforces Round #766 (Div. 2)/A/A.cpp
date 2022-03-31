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

char table[maxn][maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        for (int i=1; i<=n; i++) {
            scanf("%s", table[i] + 1);
        }

        int ans = 0;
        if (table[r][c] == 'B') {
            ans = 0;
        } else {
            bool flag = false;
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    if (table[i][j] == 'B') {
                        flag = true;
                    }
                }
            }
            if (!flag) {
                printf("-1\n");
                continue;
            }

            ans = 2;

            for (int i=1; i <= m; i++) {
                if (table[r][i] == 'B') {
                    // cerr << "bang\n";
                    ans = 1;
                }
            }

            for (int i=1; i <= n; i++) {
                if (table[i][c] == 'B') {
                    // cerr << "bang\n";
                    ans = 1;
                }
            }
        }
        // cerr << "ans = ";
        printf("%lld\n", ans);
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
