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
    int t;

    cin >> t;
    while (t--) {
        int n, U, R, D, L;
        cin >> n >> U >> R >> D >> L;

        bool ans = 0;
        for (int i=0; i<16; i++) {
            int u = U - ((i>>0)&1) - ((i>>1)&1);
            int r = R - ((i>>1)&1) - ((i>>2)&1);
            int d = D - ((i>>2)&1) - ((i>>3)&1);
            int l = L - ((i>>3)&1) - ((i>>0)&1);

            if (0 <= u && u <= n-2
             && 0 <= r && r <= n-2
             && 0 <= d && d <= n-2
             && 0 <= l && l <= n-2)
                ans = 1;
        }

        if (ans)
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
