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
const int maxn = 1e2 + 7;

char table[maxn][maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            scanf("%s", table[i] + 1);
        }
        if (table[1][1] == '1') {
            printf("-1\n");
            continue;
        }

        vector< array<int,4> > ans;

        for (int i=n; i>=1; i--) {
            for (int j=m; j>=1; j--) {
                if (table[i][j] == '1') {
                    if (j > 1) {
                        ans.PB({i, j-1, i, j});
                    } else if (i > 1) {
                        ans.PB({i-1, j, i, j});
                    }
                }
            }
        }

        // printf("ans = ");
        printf("%d\n", ans.size());
        for (auto it : ans) {
            printf("%lld %lld %lld %lld\n", it[0], it[1], it[2], it[3]);
        }
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
