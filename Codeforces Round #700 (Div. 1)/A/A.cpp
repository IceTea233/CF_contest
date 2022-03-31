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

int a[maxn] = {};

int query(int x) {
    if (a[x])
        return a[x];
    printf("? %lld\n", x);
    fflush(stdout);
    int ret;
    scanf("%lld", &ret);
    a[x] = ret;
    return ret;
}


int32_t main() {
    int i,j;
    int n;

    scanf("%lld" , &n);
    a[0] = INF;
    a[n+1] = INF;
    int l = 0;
    int r = n+1;
    int m = ( l + r ) / 2;
    while (!(l+1 == m && m+1 == r)) {
        while (l+1 < m) {
            // printf("now (%lld, %lld, %lld)\n", l, m, r);
            int x = (l + m) / 2;
            if (query(x) > query(m))
                l = x;
            else {
                r = m;
                m = x;
            }
        }
        while (m+1 < r) {
            // printf("now (%lld, %lld, %lld)\n", l, m, r);
            int x = (m+1 + r) / 2;
            if (query(x) > query(m))
                r = x;
            else {
                l = m;
                m = x;
            }
        }
    }

    int ans = m;
    printf("! %lld\n", ans);
    fflush(stdout);

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
