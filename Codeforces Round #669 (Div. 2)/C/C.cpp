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
const int maxn = 1e4 + 7;

int ans[maxn] = {};
bool v[maxn] = {};

main() {
    int i,j;
    int n;

    scanf("%lld", &n);
    int now = 1;
    for (int i=2; i<=n; i++) {
        printf("? %lld %lld\n", now, i);
        fflush(stdout);
        int k1;
        scanf("%lld", &k1);

        printf("? %lld %lld\n", i, now);
        fflush(stdout);
        int k2;
        scanf("%lld", &k2);

        if (k1 > k2) {
            // printf("set a[%lld] = %lld\n", now, k1);
            ans[now] = k1;
            v[k1] = 1;
            now = i;
        } else {
            // printf("set a[%lld] = %lld\n", i, k2);
            ans[i] = k2;
            v[k2] = 1;
        }
    }

    int idx = 0;
    int num = 0;
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            num = i;
        }
        if (!ans[i]) {
            idx = i;
        }
    }
    ans[idx] = num;

    printf("! ");
    for (int i=1; i<=n; i++) {
        printf("%lld ", ans[i]);
    }
    printf("\n");

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
