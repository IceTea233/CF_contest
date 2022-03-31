#include<bits/stdc++.h>
#define int long long
#define all(x) begin(x), end(x)
#define SZ(x) ((int)(x).size())
#define EB emplace_back
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define de(x) if(x && x == MODE)
#define MODE 0

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 1e5 + 7;

int n;
vector<int> G[maxn];
int maxi[maxn] = {};
int w[maxn] = {};

int rem_a = 0;
int rem_b = 0;
void dfs(int x, int p) {
    de(1) printf("dfs %lld >>> %lld\n", p, x);
    de(1) system("pause");
    w[x] = 1;

    for (auto y: G[x]) {
        if (y == p)
            continue;
        dfs(y, x);
        maxi[x] = max(maxi[x], w[y]);
        w[x] += w[y];
    }
    maxi[x] = max(maxi[x], n - w[x]);

    if (w[x] == 1 && !rem_a) {
        rem_a = x;
        rem_b = p;
    }
}

void dfs2(int x, int p) {
    w[x] = 1;
    de(1) printf("dfs2 %lld >>> %lld\n", p, x);
    for (auto y: G[x]) {
        if (y == p || y == rem_a)
            continue;
        dfs2(y, x);
        maxi[x] = max(maxi[x], w[y]);
        w[x] += w[y];
    }
    maxi[x] = max(maxi[x], (n-1) -  w[x]);
}

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            G[i].clear();
        }
        for (int i=1; i<=n-1; i++) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        if (n % 2 == 1) {
            printf("%lld %lld\n", 1LL, 2LL);
            printf("%lld %lld\n", 1LL, 2LL);
            continue;
        } else {
            dfs( 1, 1);

            de(1) {
                for (int i=1; i<=n; i++) {
                    printf("%lld >>> %lld\n", i, w[i]);
                }
                printf("\n");
            }

            vector<int> g;
            int mini = *min_element( maxi+1, maxi+n+1);
            for (int i=1; i<=n; i++) {
                if (maxi[i] == mini)
                    g.push_back(i);
            }
            if (g.size() > 1) {
                g.clear();

                memset(maxi, 0, sizeof(int)*(n+1));
                memset(w, 0, sizeof(int)*(n+1));
                dfs2( 1, 1);

                de(1) {
                    for (int i=1; i<=n; i++) {
                        printf("%lld >> %lld\n", i, maxi[i]);
                    }
                }
                mini = INF;
                for (int i=1; i<=n; i++) {
                    if (i == rem_a)
                        continue;
                    mini = min(mini, maxi[i]);
                }

                for (int i=1; i<=n; i++) {
                    if (maxi[i] == mini)
                        g.push_back(i);
                }
                assert(g.size() == 1);

                printf("%lld %lld\n", rem_a, rem_b);
                printf("%lld %lld\n", rem_a, g[0]);

            } else {
                printf("%lld %lld\n", 1LL, 2LL);
                printf("%lld %lld\n", 1LL, 2LL);
            }
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
