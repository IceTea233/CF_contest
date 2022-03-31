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


int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int a, b;
        scanf("%lld %lld",&a, &b);
        set<int> ans;

        int tt = a + b;
        int c = (tt + 1) / 2;
        int d = tt - c;

        if (c > a) {
            for (int i = 0; (c-a) + i <= c && i <= d; i++) {
                ans.insert((c-a) + i*2);
            }
        } else {
            for (int i = 0; (a-c) + i <= d && i <= c; i++) {
                ans.insert((a-c) + i*2);
            }
        }

        swap(c, d);

        if (c > a) {
            for (int i = 0; (c-a) + i <= c && i <= d; i++) {
                ans.insert((c-a) + i*2);
            }
        } else {
            for (int i = 0; (a-c) + i <= d && i <= c; i++) {
                // printf("add %lld\n", (a-c) + i*2);
                ans.insert((a-c) + i*2);
            }
        }

        printf("%d\n", ans.size());
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
