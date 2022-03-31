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
int b[maxn] = {};
int dis[maxn*2] = {};
int mini[maxn*2] = {};

int32_t main() {
    cin.tie(0);
    int i,j;
    int t;

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=1; i<=n; i++)
            scanf("%lld", &a[i]);
        for (int i=1; i<=n; i++)
            scanf("%lld", &b[i]);
        for (int i=1; i<=n; i++) {
            dis[b[i]] = i - 1;
        }
        mini[n*2] = dis[n*2];
        for (int i=n*2-2; i>=2; i-=2) {
            mini[i] = min(mini[i+2], dis[i]);
        }
        // for (int i=2; i<=2*n; i+=2)
        //     printf("%lld ", mini[i]);
        // printf("\n");
        int ans = INF;
        for (int i=1; i<=n; i++) {
            // printf(">>> %lld + %lld\n", i - 1, mini[a[i] + 1]);
            ans = min(ans, i - 1 + mini[a[i] + 1]);
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
