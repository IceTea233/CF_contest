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
// int bit1[maxn] = {};
// int bit2[maxn] = {};
//
// void add(int bit[], int x, int d) {
//     while (x < maxn) {
//         bit[x] += d;
//         x += x & (-x);
//     }
// }
//
// int query(int bit[], int x) {
//     int ret = 0;
//     while (x) {
//         ret += bit[x];
//         x -= x & (-x);
//     }
//     return ret;
// }

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        int extra = 0;
        int wait = 0;
        for (int i=2; i<=n-1; i++) {
            if (a[i] % 2 == 0) {
                extra += a[i] / 2;
                ans += a[i] / 2;
            } else {
                ans += (a[i] - 1) / 2;
                extra += (a[i] - 1) / 2;
            }
        }

        // cerr << "ans = ";
        if (wait > 0) {
            printf("-1\n");
        } else {
            printf("%lld\n", ans);
        }
    }

    return 0;
}

/*
          ___ ___  __________  __________
         /////\  \/\   ______\/\\\\\\\\\\\  Code by ~Ice Tea~ of
        //// \ \  \ \  \_____/\ \\\\_____/      New Empire of CHSH ...
       ////   \ \  \ \  \      \ \\\\\\\\\\\
      ////__   \ \  \ \  \      \ \\\\_____/
     ///////\   \ \  \ \  \______\ \\\\_______   ________
    ////____/    \ \__\ \___   ___\ \\\\\\\\\\\ _\  ___  \_
   /__/           \/__/\/__/\  \__/\ \\\\_____//\  .\_/\_  \
                           \ \  \   \ \\\\\\\\\\\\  \_\/_\  \
 ... with the AC Power of   \ \  \   \ \\\\_____/ \   _____  \
   The Great Tsundere Doggy. \ \  \   \ \\\\     \ \  \  \ \  \
                              \ \__\   \ \\\\\\\\\\ \__\  \ \__\
                               \/__/    \/________/\/__/   \/__/
*/
