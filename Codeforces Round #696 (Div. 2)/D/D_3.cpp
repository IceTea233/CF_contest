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
const int maxn = 2e5 + 7;

int a[maxn] = {};
int alt[maxn] = {};
int mini[maxn] = {};

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
        for (int i=1; i<=n; i++) {
            alt[i] = a[i] - alt[i-1];
        }
        mini[n+1] = INF;
        mini[n+2] = INF;
        for (int i=n; i>=1; i--) {
            mini[i] = min(mini[i+2], alt[i]);
        }
        if (mini[1] >= 0 && mini[2] >= 0 && alt[n] == 0) {
            printf("YES\n");
            continue;
        }

        bool ans = 0;
        for (int i=1; i<=n-1; i++) {
            if (alt[i] + (a[i+1] - a[i]) >= 0
            &&  mini[i+2] + (a[i+1] - a[i]) * 2 >= 0
            &&  mini[i+1] + (a[i] - a[i+1]) * 2 >= 0
            &&  alt[n] + (a[i+1] - a[i]) * (i % 2 == n % 2 ? 2: -2) == 0) {
                de(0) printf("swap(%lld, %lld)\n", i, i+1);
                ans = 1;
                break;
            }

            if (alt[i] < 0)
                break;
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
