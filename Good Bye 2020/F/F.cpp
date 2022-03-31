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
const int maxn = 5e5 + 7;
const int MOD = 1e9 + 7;

int n,m;
int k[maxn] = {};
int x[maxn][3] = {};
int take[maxn] = {};
bool ans[maxn] = {};

int32_t main() {
    int i,j;

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> k[i];
        for (int j=1; j<=k[i]; j++) {
            cin >> x[i][j];
        }
    }

    int T = 1;
    for (int i=1; i<=n; i++) {
        if (k[i] == 1) {
            take[ x[i][1] ] = i;
            ans[i] = 1;
            T = T * 2 % MOD;
        }
    }
    for (int i=1; i<=n; i++) {
        if (k[i] == 2) {
            if (!take[ x[i][1] ] || !take[ x[i][2] ]) {
                if (!take[ x[i][1] ])
                    take[ x[i][1] ] = 2;
                if (!take[ x[i][2] ])
                    take[ x[i][2] ] = 2;
                ans[i] = 1;
                T = T * 2 % MOD;
            } else {
                int cmp = max( take[ x[i][1] ], take[ x[i][2] ]);
                if (i < cmp) {
                    ans[cmp] = 0;
                    ans[i] = 1;
                    take[cmp] = i;
                }
            }
        }
    }

    vector<int> final;
    for (int i=1; i<=n; i++) {
        if (ans[i])
            final.PB(i);
    }
    printf("%lld %d\n", T, final.size());
    for (auto it: final)
        printf("%lld ", it);
    printf("\n");

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
