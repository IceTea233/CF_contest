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

multiset< vector<pii> > ans;
char s[maxn] = {};
int table[maxn][maxn] = {};

int mask[4][2] = {
    {0, 0},
    {0, 1},
    {1, 0},
    {1, 1}
};

void add(int r, int c, int x1, int y1, int x2, int y2, int x3, int y3) {
    vector<pii> tmp;
    table[r+x1][c+y1] ^= 1;
    table[r+x2][c+y2] ^= 1;
    table[r+x3][c+y3] ^= 1;
    tmp.PB({r+x1, c+y1});
    tmp.PB({r+x2, c+y2});
    tmp.PB({r+x3, c+y3});
    if (ans.find(tmp) != end(ans))
        ans.erase(tmp);
    else
        ans.insert(tmp);
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

        ans.clear();
        for (int i=1; i<=n-2; i++) {
            for (int j=1; j<=m; j+=2) {
                if (j + 1 > m) {
                    if (table[i][j] == 1) {
                        add(i, j-1, 0, 1, 1, 0, 1, 1);
                    }
                } else {
                    if (table[i][j] == 0 && table[i][j+1] == 1) {
                        add(i, j, 0, 1, 1, 0, 1, 1);
                    } else if (table[i][j] == 1 && table[i][j+1] == 0) {
                        add(i, j, 0, 0, 1, 0, 1, 1);
                    } else if (table[i][j] == 1 && table[i][j+1] == 1) {
                        add(i, j, 0, 0, 0, 1, 1, 0);
                    }
                }
            }
        }

        for (int i=1; i<=m-1; i++) {
            if (table[n-1][i] == 1 && table[n][i] == 0)
                add(n-1, i, 0, 0, 0, 1, 1, 1);
            else if (table[n-1][i] == 0 && table[n][i] == 1)
                add(n-1, i, 1, 0, 0, 1, 1, 1);
            else if (table[n-1][i] == 1 && table[n][i] == 1)
                add(n-1, i, 0, 0, 1, 0, 1, 1);
        }



        if (table[n-1][m] == 1 && table[n][m] == 0) {
            add(n-1, m-1, 0, 0, 0, 1, 1, 0);
            add(n-1, m-1, 0, 0, 0, 1, 1, 1);
            add(n-1, m-1, 0, 1, 1, 0, 1, 1);
        } else if (table[n-1][m] == 0 && table[n][m] == 1) {
            add(n-1, m-1, 0, 0, 0, 1, 1, 1);
            add(n-1, m-1, 0, 0, 1, 0, 1, 1);
            add(n-1, m-1, 0, 1, 1, 0, 1, 1);
        } else if (table[n-1][m] == 1 && table[n][m] == 1) {
            add(n-1, m-1, 0, 0, 0, 1, 1, 0);
            add(n-1, m-1, 0, 0, 1, 0, 1, 1);
        }

        printf("%d\n", ans.size());
        for (auto it: ans) {
            for (auto it2: it)
                printf("%lld %lld ", it2.F, it2.S);
            printf("\n");
        }

        de(0) {
            printf("\n");
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    printf("%lld", table[i][j]);
                }
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
