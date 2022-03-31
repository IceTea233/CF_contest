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
const int maxn = 1e3 + 7;

int c[maxn] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int n;

    cin >> n;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &c[i]);
    }

    int ans = 0;
    for (int i=1; i<=n; i+=2) {
        if (i+1 <= n) {
            ans += min(c[i], c[i+1]);
        }
        int cnt = c[i] - c[i+1];
        int mini = c[i] - c[i+1];
        // printf("cnt = %lld, mini = %lld\n", cnt, mini);
        for (int j=i+2; j<=n && mini >= 0; j++) {
            if (j % 2 == 1) {
                cnt += c[j];
            } else {
                cnt -= c[j];
                if (cnt <= mini)
                    ans ++;
                if (cnt < mini) {
                    ans += mini - max( 0LL, cnt);
                    mini = cnt;
                }
            }
            // printf("cnt = %lld, mini = %lld\n", cnt, mini);
        }
    }

    printf("%lld\n", ans);

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
