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
const int maxn = 2e5 + 7;

vector<int> G[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            G[i].clear();
        for (int i=1; i<=n; i++) {
            int k;
            cin >> k;
            for (int j=0; j<k; j++) {
                int x;
                cin >> x;
                G[x].PB(i);
            }
        }

        vector<int> in(n+7, 0);
        for (int i=1; i<=n; i++) {
            for (auto &it : G[i]) {
                in[it] ++;
            }
        }

        de(1) {
            printf(">>> ");
            for (int i=1; i<=n; i++)
                printf("%lld ", in[i]);
            printf("\n");
        }

        set<int> keep;
        for (int i=1; i<=n; i++) {
            if (!in[i])
                keep.insert(i);
        }
        int step = 0;
        while (keep.size()) {
            int goal = keep.size();
            vector<int> tmp;
            while (goal--) {
                int x = *keep.begin();
                de(1) printf("x = %lld\n", x);
                keep.erase(keep.begin());
                for (auto  &y: G[x]) {
                    if (!(--in[y])) {
                        if (y > x) {
                            goal++;
                            keep.insert(y);
                        } else {
                            tmp.PB(y);
                        }
                    }
                }
            }
            step++;
            while (tmp.size()) {
                keep.insert(tmp.back());
                tmp.PP();
            }
            de(1) printf("step = %lld\n", step);
        }

        int ans = step;
        for (int i=1; i<=n; i++) {
            if (in[i])
                ans = -1;
        }
        de (2) printf("ans =");
        printf("%lld\n", ans);
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
