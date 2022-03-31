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
const int maxn = 3e5 + 7;

int a[maxn] = {};
bool tag[maxn] = {};

bool cri(int i) {
    // if ((a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1]))
    //     printf("%lld is cri\n", i);
    return (a[i] < a[i-1] && a[i] < a[i+1]) || (a[i] > a[i-1] && a[i] > a[i+1]);
}

int32_t main() {
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            scanf("%lld", &a[i]);
        }
        a[0] = a[1];
        a[n+1] = a[n];

        int tt = 0;
        for (int i=1; i<=n; i++) {
            if (cri(i)) {
                tt++;
                tag[i] = 1;
            } else {
                tag[i] = 0;
            }
        }

        int ans = tt;
        // printf("ans = %lld?\n", tt);
        for (int i=1; i<=n; i++) {
            int tmp = a[i];
            a[i] = a[i-1];
            int now = tt;
            if (i-1 >= 1) {
                if (tag[i-1] && !cri(i-1))
                    now--;
                if (!tag[i-1] && cri(i-1))
                    now++;
            }
            if (i+1 <= n) {
                if (tag[i+1] && !cri(i+1))
                    now--;
                if (!tag[i+1] && cri(i+1))
                    now++;
            }

            if (tag[i] == 1 && !cri(i))
                now--;
            else if (!tag[i] && cri(i))
                now++;

            // printf("now = %lld\n", tt);
            ans = min(ans, now);

            de(1) {
                for (int i=1; i<=n; i++) {
                    printf("%lld ", a[i]);
                }
                printf("\n");
            }

            a[i] = a[i+1];
            now = tt;
            if (i-1 >= 1) {
                if (tag[i-1] && !cri(i-1))
                    now--;
                if (!tag[i-1] && cri(i-1))
                    now++;
            }
            if (i+1 <= n) {
                if (tag[i+1] && !cri(i+1))
                    now--;
                if (!tag[i+1] && cri(i+1))
                    now++;
            }

            if (tag[i] == 1 && !cri(i))
                now--;
            if (!tag[i] && cri(i))
                now++;

            // printf("now = %lld\n", tt);
            ans = min(ans, now);

            de(1) {
                for (int i=1; i<=n; i++) {
                    printf("%lld ", a[i]);
                }
                printf("\n");
            }

            a[i] = tmp;
        }
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
