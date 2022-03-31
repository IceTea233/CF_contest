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
const int maxn = 100 + 7;

vector< vector<pii> > ans;
char s[maxn] = {};
int table[maxn][maxn] = {};

int mask[4][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1}
};

void solve(int r, int c) {
    for (int i=0; i<4; i++) {
        int n_r = r + mask[i][0];
        int n_c = c + mask[i][1];
        if (table[n_r][n_c]) {
            for (int j=0; j<4; j++) {
                if (j == i)
                    continue;
                vector<pii> tmp;
                for (int k=0; k<4; k++) {
                    if (k == j)
                        continue;
                    int k_r = r + mask[k][0];
                    int k_c = c + mask[k][1];
                    table[k_r][k_c] ^= 1;
                    tmp.PB({k_r, k_c});
                }
                ans.PB(tmp);
            }
        }
    }
}

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            scanf("%s", s+1);
            for (int j=1; j<=m; j++) {
                if (s[j] == '0')
                    table[i][j] = 0;
                else
                    table[i][j] = 1;
            }
        }

        // printf("YEE\n");
        ans.clear();
        for (int i=1; i<=n-1; i++) {
            for (int j=1; j<=m-1; j++) {
                solve(i, j);
            }
        }

        printf("%d\n", ans.size());
        for (auto it: ans) {
            for (auto it2: it) {
                printf("%lld %lld ", it2.F, it2.S);
            }
            printf("\n");
        }

        de(0) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++)
                    printf("%lld", table[i][j]);
                printf("\n");
            }
            printf("\n");
        }
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
