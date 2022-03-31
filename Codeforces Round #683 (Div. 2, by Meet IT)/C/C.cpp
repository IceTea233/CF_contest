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

int w[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n, W;
        cin >> n >> W;
        vector<pii> keep;
        for (int i=1; i<=n; i++) {
            cin >> w[i];
            keep.PB({w[i], i});
        }
        sort(all(keep), greater<pii>());
        int sum = 0;
        vector<int> ans;
        for (auto it: keep) {
            if (sum + it.F <= W) {
                sum += it.F;
                ans.PB(it.S);
            }
        }
        if (sum >= (W+1) / 2) {
            printf("%d\n", ans.size());
            for (auto it: ans) {
                printf("%lld ", it);
            }
            printf("\n");
        } else {
            printf("-1\n");
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
