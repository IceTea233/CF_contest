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
const int maxn = 2e5 + 7;

int a[maxn] = {};
int b[maxn] = {};

bool cmp(pii a, pii b) {
    return (double) a.F / a.S > (double) b.F / b.S;
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld", &b[i]);

        vector<pii> keep;
        for (int i=1; i<=n; i++) {
            keep.PB({a[i], b[i]});
        }
        sort(all(keep), cmp);
        // for (auto it : keep)
        //     printf("%lld ", it.F);
        // printf("\n");
        // for (auto it : keep)
        //     printf("%lld ", it.S);
        // printf("\n");
        int tt = 0;
        int cost = 0;
        for (i=0; i<n; i++) {
            tt += keep[i].F;
            cost += keep[i].S;
            if (tt >= m)
                break;
        }

        if (tt < m) {
            printf("-1\n");
        } else {
            int ans = cost;
            int r = -1;
            for (int j=i+1; j<n; j++) {
                if (keep[j].S == 1) {
                    r = j;
                    break;
                }
            }
            int l = -1;
            for (int j=i; j>=0; j--) {
                if (keep[j].S == 2) {
                    l = j;
                    break;
                }
            }
            if (l > -1 && r > -1) {
                if (tt - keep[l].F + keep[r].F >= m) {
                    ans = cost-1;
                }
            }
            l = -1;
            for (int j=i; j>=0; j--) {
                if (keep[j].S == 1) {
                    l = j;
                    break;
                }
            }
            if (l > -1 && tt - keep[l].F >= m)
                ans = cost-1;

            de(0) printf("ans = ");
            printf("%lld\n", ans);
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
