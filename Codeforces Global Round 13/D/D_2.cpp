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
    int i,j;
    int q;

    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        bool ans = 1;
        int x = u;
        for (int i=0; i<=30; i++) {
            if (((x>>i)&1) == 0) {
                // printf("cmd 1\n");
                if (((v>>i)&1) == 1) {
                    if (((u>>i)&1) == 0) {
                        ans = 0;
                    } else {
                        x += (1<<i);
                    }
                }
            } else {
                // printf("cmd 2\n");
                if (((v>>i)&1) == 0) {
                    x += (1<<i);
                }
            }
        }
        // printf("x = %lld\n", x);

        if (x == v && ans)
            printf("YES\n");
        else
            printf("NO\n");
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
