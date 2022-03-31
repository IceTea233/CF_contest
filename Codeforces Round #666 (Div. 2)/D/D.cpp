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
#define MODE 1

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e18;
const int maxn = 107;

int a[maxn] = {};

main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (i=1; i<=n; i++) {
            cin >> a[i];
        }

        bool ans = 0;
        int last = 0;
        while (1) {
            int maxi = 0;
            int idx = 0;
            for (i=1; i<=n; i++) {
                if (i == last)
                    continue;
                if (a[i] > a[idx]) {
                    idx = i;
                }
            }
            if (idx == 0)
                break;

            a[idx]--;
            last = idx;
            ans ^= 1;
        }

        if (ans)
            printf("T\n");
        else
            printf("HL\n");
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
