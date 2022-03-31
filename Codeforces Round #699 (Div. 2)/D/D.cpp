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
const int maxn = 1e3 + 7;

char adj[maxn][maxn];

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i=1; i<=n; i++) {
            scanf("%s", adj[i]+1);
        }

        vector<int> ans;
        if (m % 2 == 1) {
            ans.PB(1);
            for (int i=2; i<=m+1; i++)
                ans.PB(i % 2 ? 1 : 2);
        } else {
            if (n == 2) {
                if (adj[1][2] != adj[2][1]) {
                    printf("NO\n");
                    continue;
                }
            }

            for (int i=1; i<=n; i++) {
                for (int j=i+1; j<=n; j++) {
                    if (adj[i][j] == adj[j][i]) {
                        ans.PB(i);
                        for (int k=2; k<=m+1; k++) {
                            ans.PB(k % 2 ? i : j);
                        }
                        break;
                    }
                }
                if (ans.size())
                    break;
            }

            if (ans.empty()) {
                vector<int> cir(4, 0);
                if (adj[1][2] == adj[2][3]) {
                    cir = {1, 2, 3, 2};
                } else if (adj[1][3] == adj[3][2]) {
                    cir = {1, 3, 2, 3};
                } else {
                    cir = {3, 1, 2, 1};
                }

                if (m % 4 == 2) {
                    for (int i=0; i<m+1; i++) {
                        ans.PB(cir[i%4]);
                    }
                } else {
                    for (int i=0; i<m+1; i++) {
                        ans.PB(cir[(i+1)%4]);
                    }
                }
            }
        }
        printf("YES\n");
        for (auto it : ans)
            printf("%lld ", it);
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
