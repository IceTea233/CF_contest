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
const int maxn = 1e2 + 7;

char s[maxn] = {};

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        scanf("%s", s+1);
        while(q--) {
            int l, r;
            cin >> l >> r;


            int ans = 0;
            for (int j=l; j<r; j++) {
                int idx = l;
                for (i=1; i<=n && idx <= j; i++) {
                    if (s[i] == s[idx]) {
                        idx++;
                    }
                }

                de(1) printf("cut = %lld\n", i);
                for (i++; i<=n && idx <= r; i++) {
                    if (s[i] == s[idx]) {
                        idx++;
                    }
                    if (idx > r)
                        break;
                }

                if (i <= n) {
                    de(1) printf(">>> %lld\n", i);
                    ans = 1;
                    break;
                }
            }


            if (i <= n)
                printf("YES\n");
            else
                printf("NO\n");
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
