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

int a[maxn] = {};
int b[maxn] = {};
int c[maxn] = {};
int ans[maxn] = {};
int dft[maxn] = {};

vector<int> pos[maxn];

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            dft[i] = 0;
        }
        for (int i=1; i<=n; i++) {
            pos[i].clear();
        }
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        for (int i=1; i<=n; i++) {
            cin >> b[i];
        }
        for (int i=1; i<=m; i++) {
            cin >> c[i];
        }

        for (int i=1; i<=n; i++) {
            if (a[i] != b[i]) {
                pos[b[i]].PB(i);
                if (!dft[b[i]])
                    dft[b[i]] = i;
            }
        }

        for (int i=1; i<=n; i++) {
            if (!dft[b[i]])
                dft[b[i]] = i;
        }

        int final;
        if (!dft[c[m]]) {
            printf("NO\n");
            continue;
        } else {
            final = dft[c[m]];
        }
        // printf("chk\n");

        for (int i=1; i<m; i++) {
            int color = c[i];
            if (pos[color].empty()) {
                ans[i] = final;
            } else {
                ans[i] = pos[color].back();
                if (pos[color].size() > 1)
                    pos[color].PP();
                a[ans[i]] = c[i];
            }
        }
        a[final] = c[m];
        ans[m] = final;

        bool chk = 1;
        for (int i=1; i<=n; i++) {
            if (a[i] != b[i])
                chk = 0;
        }
        if (chk) {
            printf("YES\n");
            for (int i=1; i<=m; i++)
                printf("%lld ", ans[i]);
            printf("\n");
        } else {
            printf("No\n");
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
